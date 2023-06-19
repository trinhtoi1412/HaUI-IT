create database QLBanHang2
go
use QLBanHang2

create table LoaiSP(
	MaLoai char(10) primary key,
	TenLoai nvarchar(50)
)
create table SanPham(
	MaSP char(10) primary key,
	TenSP nvarchar(50),
	DonGia float,
	SoLuongCo int,
	MaLoai char(10) not null,
	constraint FK_SP foreign key(MaLoai) references LoaiSP(MaLoai)
)
create table HoaDonChiTiet(
	MaHD char(10) not null,
	MaSP char(10) not null,
	NgayBan int,
	SoLuongMua int,
	constraint PK_CTHD primary key(MaHD,MaSP),
	constraint FK_CTHD foreign key(MaSP) references SanPham(MaSP)
)
insert into LoaiSP values
('L01',N'Điện thoại'),
('L02',N'Laptop'),
('L03',N'Tủ lạnh');
insert into SanPham values
('SP01',N'IPhone 13',2300,12,'L01'),
('SP02',N'Tosiba',3500,8,'L03'),
('SP03',N'Acer Nitro',3400,10,'L02'),
('SP04',N'Galaxy Y',1500,18,'L01');
insert into HoaDonChiTiet values
('HD01','SP01',13,3),
('HD02','SP03',24,5),
('HD03','SP02',02,2),
('HD04','SP01',18,1);

select * from SanPham