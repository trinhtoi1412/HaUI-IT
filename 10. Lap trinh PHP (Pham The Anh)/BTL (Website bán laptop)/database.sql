-- phpMyAdmin SQL Dump
-- version 4.9.1
-- https://www.phpmyadmin.net/
--
-- Máy chủ: localhost
-- Thời gian đã tạo: Th6 19, 2023 lúc 06:15 AM
-- Phiên bản máy phục vụ: 8.0.17
-- Phiên bản PHP: 7.3.10

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Cơ sở dữ liệu: `websites-nhom1`
--

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `brands`
--

CREATE TABLE `brands` (
  `IDBrand` int(11) NOT NULL,
  `Name` varchar(100) COLLATE utf8mb4_general_ci NOT NULL,
  `Image` varchar(200) COLLATE utf8mb4_general_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Đang đổ dữ liệu cho bảng `brands`
--

INSERT INTO `brands` (`IDBrand`, `Name`, `Image`) VALUES
(16, 'DELL123', 'image/logoDELL.jpg');

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `cart`
--

CREATE TABLE `cart` (
  `id` int(11) NOT NULL,
  `customer_name` varchar(100) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT NULL,
  `product_id` int(11) DEFAULT NULL,
  `quantity` int(11) DEFAULT NULL,
  `price` decimal(10,2) DEFAULT NULL,
  `total` decimal(10,2) GENERATED ALWAYS AS ((`quantity` * `price`)) STORED,
  `created_at` datetime DEFAULT NULL ON UPDATE CURRENT_TIMESTAMP,
  `additional_info` text
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Đang đổ dữ liệu cho bảng `cart`
--

INSERT INTO `cart` (`id`, `customer_name`, `product_id`, `quantity`, `price`, `created_at`, `additional_info`) VALUES
(1, 'Toquythanh2k3', 3, 6, '1500000.00', '2023-06-19 13:06:20', NULL),
(3, 'Toquythanh2k3', 4, 3, '1500000.00', '2023-06-19 13:06:20', NULL);

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `danhmuc`
--

CREATE TABLE `danhmuc` (
  `IDDanhMuc` int(11) NOT NULL,
  `TenDanhMuc` varchar(100) COLLATE utf8mb4_general_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Đang đổ dữ liệu cho bảng `danhmuc`
--

INSERT INTO `danhmuc` (`IDDanhMuc`, `TenDanhMuc`) VALUES
(1, 'laptop Gaming'),
(20, 'laptop Gaming'),
(21, 'laptop11123');

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `giohang`
--

CREATE TABLE `giohang` (
  `IDGioHang` int(11) NOT NULL,
  `SoLuong` int(11) NOT NULL,
  `IDProduct` int(11) NOT NULL,
  `IDTaiKhoan` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `khuyenmai`
--

CREATE TABLE `khuyenmai` (
  `IDKhuyenMai` int(11) NOT NULL,
  `tenkhuyenmai` varchar(300) COLLATE utf8mb4_general_ci NOT NULL,
  `GiamGia` int(11) NOT NULL,
  `NgayBatDau` datetime NOT NULL,
  `NgayKetThuc` datetime NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Đang đổ dữ liệu cho bảng `khuyenmai`
--

INSERT INTO `khuyenmai` (`IDKhuyenMai`, `tenkhuyenmai`, `GiamGia`, `NgayBatDau`, `NgayKetThuc`) VALUES
(1, 'KM1', 10, '2023-06-11 00:00:00', '2023-06-13 00:00:00'),
(2, 'KM1', 10, '2023-06-11 00:00:00', '2023-06-13 00:00:00');

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `orderproduct`
--

CREATE TABLE `orderproduct` (
  `IDOrder` int(11) NOT NULL,
  `IDProduct` int(11) NOT NULL,
  `SoLuong` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `orders`
--

CREATE TABLE `orders` (
  `IDOrder` int(11) NOT NULL,
  `NameReceiver` varchar(200) COLLATE utf8mb4_general_ci NOT NULL,
  `AddressReceiver` varchar(300) COLLATE utf8mb4_general_ci NOT NULL,
  `PhoneReceiver` varchar(20) COLLATE utf8mb4_general_ci NOT NULL,
  `Note` text COLLATE utf8mb4_general_ci NOT NULL,
  `Status` varchar(100) COLLATE utf8mb4_general_ci NOT NULL,
  `CreateTime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `product`
--

CREATE TABLE `product` (
  `IDProduct` int(11) NOT NULL,
  `NameProduct` varchar(200) COLLATE utf8mb4_general_ci NOT NULL,
  `Price` varchar(30) COLLATE utf8mb4_general_ci NOT NULL,
  `SoLuong` int(11) NOT NULL,
  `Image` varchar(200) COLLATE utf8mb4_general_ci NOT NULL,
  `CPU` varchar(200) COLLATE utf8mb4_general_ci NOT NULL,
  `RAM` varchar(200) COLLATE utf8mb4_general_ci NOT NULL,
  `Disk` varchar(200) COLLATE utf8mb4_general_ci NOT NULL,
  `VGA` varchar(200) COLLATE utf8mb4_general_ci NOT NULL,
  `Screen` varchar(200) COLLATE utf8mb4_general_ci NOT NULL,
  `IDDanhMuc` int(11) NOT NULL,
  `IDBrand` int(11) NOT NULL,
  `IDKhuyenMai` int(11) DEFAULT NULL,
  `Description` text COLLATE utf8mb4_general_ci
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Đang đổ dữ liệu cho bảng `product`
--

INSERT INTO `product` (`IDProduct`, `NameProduct`, `Price`, `SoLuong`, `Image`, `CPU`, `RAM`, `Disk`, `VGA`, `Screen`, `IDDanhMuc`, `IDBrand`, `IDKhuyenMai`, `Description`) VALUES
(2, 'Dell 5570', '1500000', 12, 'https://laptop88.vn/media/product/250_8017_7896_7716_7015_6904_dell_inspiron_15_3511_70270650_1.jpg', 'I5 8250U', '8GB', '256GB', '160TI', '15 inch', 20, 16, 1, 'Khong '),
(3, 'Dell 5570', '1500000', 12, 'https://laptop88.vn/media/product/250_8017_7896_7716_7015_6904_dell_inspiron_15_3511_70270650_1.jpg', 'I5 8250U', '8GB', '256GB', '160TI', '15 inch', 20, 16, 1, 'Khong '),
(130, 'Dell 5570', '1500000', 12, 'https://laptop88.vn/media/product/250_7575_dell_latitude_5410_jakarta_1.jpg', 'I5 8250U', '8GB', '256GB', '160TI', '15 inch', 20, 16, 1, 'Khong'),
(131, 'Dell 5570', '1500000', 12, 'https://laptop88.vn/media/product/250_7575_dell_latitude_5410_jakarta_1.jpg', 'I5 8250U', '8GB', '256GB', '160TI', '15 inch', 20, 16, 1, 'Khong'),
(132, 'Dell 5570', '1500000', 12, 'https://laptop88.vn/media/product/250_7575_dell_latitude_5410_jakarta_1.jpg', 'I5 8250U', '8GB', '256GB', '160TI', '15 inch', 20, 16, 1, 'Khong'),
(133, 'Dell 5570', '1500000', 12, 'https://laptop88.vn/media/product/250_7575_dell_latitude_5410_jakarta_1.jpg', 'I5 8250U', '8GB', '256GB', '160TI', '15 inch', 20, 16, 1, 'Khong'),
(134, 'Dell 5570', '1500000', 12, 'https://laptop88.vn/media/product/250_7575_dell_latitude_5410_jakarta_1.jpg', 'I5 8250U', '8GB', '256GB', '160TI', '15 inch', 20, 16, 1, 'Khong'),
(135, 'Dell 5570', '1500000', 12, 'https://laptop88.vn/media/product/250_7575_dell_latitude_5410_jakarta_1.jpg', 'I5 8250U', '8GB', '256GB', '160TI', '15 inch', 20, 16, 1, 'Khong'),
(136, 'Dell 5570', '1500000', 12, 'https://laptop88.vn/media/product/250_7575_dell_latitude_5410_jakarta_1.jpg', 'I5 8250U', '8GB', '256GB', '160TI', '15 inch', 20, 16, 1, 'Khong'),
(137, 'Dell 5570', '1500000', 12, 'https://laptop88.vn/media/product/250_7575_dell_latitude_5410_jakarta_1.jpg', 'I5 8250U', '8GB', '256GB', '160TI', '15 inch', 20, 16, 1, 'Khong'),
(138, 'Dell 5570', '1500000', 12, 'https://laptop88.vn/media/product/250_7575_dell_latitude_5410_jakarta_1.jpg', 'I5 8250U', '8GB', '256GB', '160TI', '15 inch', 20, 16, 1, 'Khong'),
(139, 'Dell 5570', '1500000', 12, 'https://laptop88.vn/media/product/250_7575_dell_latitude_5410_jakarta_1.jpg', 'I5 8250U', '8GB', '256GB', '160TI', '15 inch', 20, 16, 1, 'Khong'),
(140, 'Dell 5570', '1500000', 12, 'https://laptop88.vn/media/product/250_7575_dell_latitude_5410_jakarta_1.jpg', 'I5 8250U', '8GB', '256GB', '160TI', '15 inch', 20, 16, 1, 'Khong'),
(141, 'Dell 5570', '1500000', 12, 'https://laptop88.vn/media/product/250_7575_dell_latitude_5410_jakarta_1.jpg', 'I5 8250U', '8GB', '256GB', '160TI', '15 inch', 20, 16, 1, 'Khong'),
(142, 'Dell 5570', '1500000', 12, 'https://laptop88.vn/media/product/250_7575_dell_latitude_5410_jakarta_1.jpg', 'I5 8250U', '8GB', '256GB', '160TI', '15 inch', 20, 16, 1, 'Khong'),
(143, 'Dell 5570', '1500000', 12, 'https://laptop88.vn/media/product/250_7575_dell_latitude_5410_jakarta_1.jpg', 'I5 8250U', '8GB', '256GB', '160TI', '15 inch', 20, 16, 1, 'Khong'),
(144, 'Dell 5570', '1500000', 12, 'https://laptop88.vn/media/product/250_7575_dell_latitude_5410_jakarta_1.jpg', 'I5 8250U', '8GB', '256GB', '160TI', '15 inch', 20, 16, 1, 'Khong'),
(145, 'Dell 5570', '1500000', 12, 'https://laptop88.vn/media/product/250_7575_dell_latitude_5410_jakarta_1.jpg', 'I5 8250U', '8GB', '256GB', '160TI', '15 inch', 20, 16, 1, 'Khong'),
(146, 'Dell 5570', '1500000', 12, 'https://laptop88.vn/media/product/250_7575_dell_latitude_5410_jakarta_1.jpg', 'I5 8250U', '8GB', '256GB', '160TI', '15 inch', 20, 16, 1, 'Khong'),
(147, 'Dell 5570', '1500000', 12, 'https://laptop88.vn/media/product/250_7575_dell_latitude_5410_jakarta_1.jpg', 'I5 8250U', '8GB', '256GB', '160TI', '15 inch', 20, 16, 1, 'Khong'),
(148, 'Dell 5570', '1500000', 12, 'https://laptop88.vn/media/product/250_7575_dell_latitude_5410_jakarta_1.jpg', 'I5 8250U', '8GB', '256GB', '160TI', '15 inch', 20, 16, 1, 'Khong'),
(149, 'Dell 5570', '1500000', 12, 'https://laptop88.vn/media/product/250_7575_dell_latitude_5410_jakarta_1.jpg', 'I5 8250U', '8GB', '256GB', '160TI', '15 inch', 20, 16, 1, 'Khong'),
(150, 'Dell 5570', '1500000', 12, 'https://laptop88.vn/media/product/250_7575_dell_latitude_5410_jakarta_1.jpg', 'I5 8250U', '8GB', '256GB', '160TI', '15 inch', 20, 16, 1, 'Khong'),
(151, 'Dell 5570', '1500000', 12, 'https://laptop88.vn/media/product/250_7575_dell_latitude_5410_jakarta_1.jpg', 'I5 8250U', '8GB', '256GB', '160TI', '15 inch', 20, 16, 1, 'Khong'),
(152, 'Dell 5570', '1500000', 12, 'https://laptop88.vn/media/product/250_7575_dell_latitude_5410_jakarta_1.jpg', 'I5 8250U', '8GB', '256GB', '160TI', '15 inch', 20, 16, 1, 'Khong'),
(153, 'Dell 5570', '1500000', 12, 'https://laptop88.vn/media/product/250_7575_dell_latitude_5410_jakarta_1.jpg', 'I5 8250U', '8GB', '256GB', '160TI', '15 inch', 20, 16, 1, 'Khong'),
(154, 'Dell 5570', '1500000', 12, 'https://laptop88.vn/media/product/250_7575_dell_latitude_5410_jakarta_1.jpg', 'I5 8250U', '8GB', '256GB', '160TI', '15 inch', 20, 16, 1, 'Khong'),
(155, 'Dell 5570', '1500000', 12, 'https://laptop88.vn/media/product/250_7575_dell_latitude_5410_jakarta_1.jpg', 'I5 8250U', '8GB', '256GB', '160TI', '15 inch', 20, 16, 1, 'Khong'),
(156, 'Dell 5570', '1500000', 12, 'https://laptop88.vn/media/product/250_7575_dell_latitude_5410_jakarta_1.jpg', 'I5 8250U', '8GB', '256GB', '160TI', '15 inch', 20, 16, 1, 'Khong'),
(157, 'Dell 5570', '1500000', 12, 'https://laptop88.vn/media/product/250_7575_dell_latitude_5410_jakarta_1.jpg', 'I5 8250U', '8GB', '256GB', '160TI', '15 inch', 20, 16, 1, 'Khong');

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `role`
--

CREATE TABLE `role` (
  `IDRole` int(11) NOT NULL,
  `name` varchar(20) COLLATE utf8mb4_general_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Đang đổ dữ liệu cho bảng `role`
--

INSERT INTO `role` (`IDRole`, `name`) VALUES
(1, 'admin'),
(2, 'user');

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `taikhoan`
--

CREATE TABLE `taikhoan` (
  `IDTaiKhoan` int(11) NOT NULL,
  `User` varchar(100) COLLATE utf8mb4_general_ci NOT NULL,
  `Password` varchar(30) COLLATE utf8mb4_general_ci NOT NULL,
  `Address` varchar(500) COLLATE utf8mb4_general_ci NOT NULL,
  `Phone` varchar(20) COLLATE utf8mb4_general_ci NOT NULL,
  `FullName` varchar(300) COLLATE utf8mb4_general_ci NOT NULL,
  `Email` varchar(300) COLLATE utf8mb4_general_ci NOT NULL,
  `IDRole` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Đang đổ dữ liệu cho bảng `taikhoan`
--

INSERT INTO `taikhoan` (`IDTaiKhoan`, `User`, `Password`, `Address`, `Phone`, `FullName`, `Email`, `IDRole`) VALUES
(2, 'Toquythanh2k3', '123123123', '', '', '', '', 2);

--
-- Chỉ mục cho các bảng đã đổ
--

--
-- Chỉ mục cho bảng `brands`
--
ALTER TABLE `brands`
  ADD PRIMARY KEY (`IDBrand`);

--
-- Chỉ mục cho bảng `cart`
--
ALTER TABLE `cart`
  ADD PRIMARY KEY (`id`);

--
-- Chỉ mục cho bảng `danhmuc`
--
ALTER TABLE `danhmuc`
  ADD PRIMARY KEY (`IDDanhMuc`);

--
-- Chỉ mục cho bảng `giohang`
--
ALTER TABLE `giohang`
  ADD PRIMARY KEY (`IDGioHang`),
  ADD KEY `FK_GIoHang_TaiKhoan` (`IDTaiKhoan`),
  ADD KEY `FK_GIoHang_Product` (`IDProduct`);

--
-- Chỉ mục cho bảng `khuyenmai`
--
ALTER TABLE `khuyenmai`
  ADD PRIMARY KEY (`IDKhuyenMai`);

--
-- Chỉ mục cho bảng `orderproduct`
--
ALTER TABLE `orderproduct`
  ADD PRIMARY KEY (`IDOrder`,`IDProduct`),
  ADD KEY `FK_OrderProduct_Product` (`IDProduct`);

--
-- Chỉ mục cho bảng `orders`
--
ALTER TABLE `orders`
  ADD PRIMARY KEY (`IDOrder`);

--
-- Chỉ mục cho bảng `product`
--
ALTER TABLE `product`
  ADD PRIMARY KEY (`IDProduct`),
  ADD KEY `FK_Product_Brands` (`IDBrand`),
  ADD KEY `FK_Product_KhuyenMai` (`IDKhuyenMai`),
  ADD KEY `FK_Product_DanhMuc` (`IDDanhMuc`);

--
-- Chỉ mục cho bảng `role`
--
ALTER TABLE `role`
  ADD PRIMARY KEY (`IDRole`);

--
-- Chỉ mục cho bảng `taikhoan`
--
ALTER TABLE `taikhoan`
  ADD PRIMARY KEY (`IDTaiKhoan`),
  ADD KEY `IDRole` (`IDRole`);

--
-- AUTO_INCREMENT cho các bảng đã đổ
--

--
-- AUTO_INCREMENT cho bảng `brands`
--
ALTER TABLE `brands`
  MODIFY `IDBrand` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=18;

--
-- AUTO_INCREMENT cho bảng `cart`
--
ALTER TABLE `cart`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT cho bảng `danhmuc`
--
ALTER TABLE `danhmuc`
  MODIFY `IDDanhMuc` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=22;

--
-- AUTO_INCREMENT cho bảng `giohang`
--
ALTER TABLE `giohang`
  MODIFY `IDGioHang` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT cho bảng `khuyenmai`
--
ALTER TABLE `khuyenmai`
  MODIFY `IDKhuyenMai` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT cho bảng `orders`
--
ALTER TABLE `orders`
  MODIFY `IDOrder` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT cho bảng `product`
--
ALTER TABLE `product`
  MODIFY `IDProduct` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=158;

--
-- AUTO_INCREMENT cho bảng `role`
--
ALTER TABLE `role`
  MODIFY `IDRole` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT cho bảng `taikhoan`
--
ALTER TABLE `taikhoan`
  MODIFY `IDTaiKhoan` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- Các ràng buộc cho các bảng đã đổ
--

--
-- Các ràng buộc cho bảng `giohang`
--
ALTER TABLE `giohang`
  ADD CONSTRAINT `FK_GIoHang_Product` FOREIGN KEY (`IDProduct`) REFERENCES `product` (`IDProduct`),
  ADD CONSTRAINT `FK_GIoHang_TaiKhoan` FOREIGN KEY (`IDTaiKhoan`) REFERENCES `taikhoan` (`IDTaiKhoan`);

--
-- Các ràng buộc cho bảng `orderproduct`
--
ALTER TABLE `orderproduct`
  ADD CONSTRAINT `FK_OrderProduct_Orders` FOREIGN KEY (`IDOrder`) REFERENCES `orders` (`IDOrder`),
  ADD CONSTRAINT `FK_OrderProduct_Product` FOREIGN KEY (`IDProduct`) REFERENCES `product` (`IDProduct`);

--
-- Các ràng buộc cho bảng `product`
--
ALTER TABLE `product`
  ADD CONSTRAINT `FK_Product_Brands` FOREIGN KEY (`IDBrand`) REFERENCES `brands` (`IDBrand`),
  ADD CONSTRAINT `FK_Product_DanhMuc` FOREIGN KEY (`IDDanhMuc`) REFERENCES `danhmuc` (`IDDanhMuc`),
  ADD CONSTRAINT `FK_Product_KhuyenMai` FOREIGN KEY (`IDKhuyenMai`) REFERENCES `khuyenmai` (`IDKhuyenMai`);

--
-- Các ràng buộc cho bảng `taikhoan`
--
ALTER TABLE `taikhoan`
  ADD CONSTRAINT `taikhoan_ibfk_1` FOREIGN KEY (`IDRole`) REFERENCES `role` (`IDRole`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
