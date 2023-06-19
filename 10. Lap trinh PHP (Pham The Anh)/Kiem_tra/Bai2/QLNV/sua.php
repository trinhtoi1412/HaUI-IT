<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <title>Trang sửa</title>
    <link rel="stylesheet" href="">
</head>
<body>
    <?php
    $kn2 = mysqli_connect('localhost', 'root', '', 'qlnv');
    if (!$kn2) {
        echo "Kết nối thất bại: " . mysqli_connect_error();
        exit();
    }

    if (isset($_GET['MaNV'])) {
        $manv = $_GET['MaNV'];

        $sql = "SELECT * FROM nhanvien WHERE MaNV='$manv'";
        $kq = mysqli_query($kn2, $sql);

        if (!$kq) {
            die("Lỗi truy vấn: " . mysqli_error($kn2));
        }

        $row = mysqli_fetch_assoc($kq);
    }
    ?>

    <h2 align="center">Thông tin nhân viên</h2>
    <form action="xn_sua.php" method="post" enctype="multipart/form-data">
        <table border="1" align="center">
            <tr>
                <td>Mã nhân viên:</td>
                <td><input type="text" name="manv" value="<?php echo $row['MaNV']; ?>" readonly></td>
            </tr>
            <tr>
                <td>Tên nhân viên:</td>
                <td><input type="text" name="hoten" value="<?php echo $row['HoTen']; ?>"></td>
            </tr>
            <tr>
                <td>Hình ảnh:</td>
                <td><input type="file" name="hinhanh"></td>
            </tr>
            <tr>
                <td>Xếp loại:</td>
                <td><input type="text" name="xeploai" value="<?php echo $row['XepLoai']; ?>"></td>
            </tr>
            <tr>
                <td>Lương ngày:</td>
                <td><input type="text" name="luongngay" value="<?php echo $row['LuongNgay']; ?>"></td>
            </tr>
            <tr>
                <td>Ngày công:</td>
                <td><input type="text" name="ngaycong" value="<?php echo $row['NgayCong']; ?>"></td>
            </tr>
            <tr>
                <td colspan="2" align="right"><input type="submit" value="CẬP NHẬT"></td>
            </tr>
        </table>
    </form>
</body>
</html>