using System;
using System.Collections.Generic;
using Microsoft.EntityFrameworkCore;

namespace Onthi2.Models;

public partial class QlbanHang2Context : DbContext
{
    public QlbanHang2Context()
    {
    }

    public QlbanHang2Context(DbContextOptions<QlbanHang2Context> options)
        : base(options)
    {
    }

    public virtual DbSet<HoaDonChiTiet> HoaDonChiTiets { get; set; }

    public virtual DbSet<LoaiSp> LoaiSps { get; set; }

    public virtual DbSet<SanPham> SanPhams { get; set; }

    protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
#warning To protect potentially sensitive information in your connection string, you should move it out of source code. You can avoid scaffolding the connection string by using the Name= syntax to read it from configuration - see https://go.microsoft.com/fwlink/?linkid=2131148. For more guidance on storing connection strings, see http://go.microsoft.com/fwlink/?LinkId=723263.
        => optionsBuilder.UseSqlServer("Data Source=LAPTOP-STF1P35M\\HUY;Initial Catalog=QLBanHang2;Integrated Security=True");

    protected override void OnModelCreating(ModelBuilder modelBuilder)
    {
        modelBuilder.Entity<HoaDonChiTiet>(entity =>
        {
            entity.HasKey(e => new { e.MaHd, e.MaSp }).HasName("PK_CTHD");

            entity.ToTable("HoaDonChiTiet");

            entity.Property(e => e.MaHd)
                .HasMaxLength(10)
                .IsUnicode(false)
                .IsFixedLength()
                .HasColumnName("MaHD");
            entity.Property(e => e.MaSp)
                .HasMaxLength(10)
                .IsUnicode(false)
                .IsFixedLength()
                .HasColumnName("MaSP");

            entity.HasOne(d => d.MaSpNavigation).WithMany(p => p.HoaDonChiTiets)
                .HasForeignKey(d => d.MaSp)
                .OnDelete(DeleteBehavior.ClientSetNull)
                .HasConstraintName("FK_CTHD");
        });

        modelBuilder.Entity<LoaiSp>(entity =>
        {
            entity.HasKey(e => e.MaLoai).HasName("PK__LoaiSP__730A5759FFA7C9C1");

            entity.ToTable("LoaiSP");

            entity.Property(e => e.MaLoai)
                .HasMaxLength(10)
                .IsUnicode(false)
                .IsFixedLength();
            entity.Property(e => e.TenLoai).HasMaxLength(50);
        });

        modelBuilder.Entity<SanPham>(entity =>
        {
            entity.HasKey(e => e.MaSp).HasName("PK__SanPham__2725081C4604398F");

            entity.ToTable("SanPham");

            entity.Property(e => e.MaSp)
                .HasMaxLength(10)
                .IsUnicode(false)
                .IsFixedLength()
                .HasColumnName("MaSP");
            entity.Property(e => e.MaLoai)
                .HasMaxLength(10)
                .IsUnicode(false)
                .IsFixedLength();
            entity.Property(e => e.TenSp)
                .HasMaxLength(50)
                .HasColumnName("TenSP");

            entity.HasOne(d => d.MaLoaiNavigation).WithMany(p => p.SanPhams)
                .HasForeignKey(d => d.MaLoai)
                .OnDelete(DeleteBehavior.ClientSetNull)
                .HasConstraintName("FK_SP");
        });

        OnModelCreatingPartial(modelBuilder);
    }

    partial void OnModelCreatingPartial(ModelBuilder modelBuilder);
}
