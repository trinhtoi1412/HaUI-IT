using System;
using System.Collections.Generic;

namespace Onthi2.Models;

public partial class SanPham
{
    public string MaSp { get; set; } = null!;

    public string? TenSp { get; set; }

    public double? DonGia { get; set; }

    public int? SoLuongCo { get; set; }

    public string MaLoai { get; set; } = null!;

    public virtual ICollection<HoaDonChiTiet> HoaDonChiTiets { get; } = new List<HoaDonChiTiet>();

    public virtual LoaiSp MaLoaiNavigation { get; set; } = null!;
}
