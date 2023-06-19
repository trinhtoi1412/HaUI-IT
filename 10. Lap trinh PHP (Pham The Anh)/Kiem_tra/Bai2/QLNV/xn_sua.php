<?php
$database_host = 'localhost';
$database_user = 'root';
$database_password = '';
$database_name = 'qlnv';

$kn = mysqli_connect($database_host, $database_user, $database_password, $database_name);
if (!$kn) {
    die("Kết nối thất bại: " . mysqli_connect_error());
}

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $manv = $_POST['manv'];
    $hoten = $_POST['hoten'];
    $xeploai = $_POST['xeploai'];
    $luongngay = $_POST['luongngay'];
    $ngaycong = $_POST['ngaycong'];

    // Kiểm tra xem có tệp được tải lên không
    if (isset($_FILES['hinhanh']) && $_FILES['hinhanh']['error'] === UPLOAD_ERR_OK) {
        $hinhanh = $_FILES['hinhanh']['name'];
        $hinhanh_tmp = $_FILES['hinhanh']['tmp_name'];
        $hinhanh = time() . '_' . $hinhanh;
        $upload_dir = 'Ảnh/';

        if (move_uploaded_file($hinhanh_tmp, $upload_dir . $hinhanh)) {
            $sql = "UPDATE nhanvien SET HoTen='$hoten', HinhAnh='$hinhanh', XepLoai='$xeploai', LuongNgay='$luongngay', NgayCong='$ngaycong' WHERE MaNV='$manv'";
            $kq = mysqli_query($kn, $sql);

            if (!$kq) {
                die("Lỗi truy vấn: " . mysqli_error($kn));
            } else {
                echo "Cập nhật thành công";
            }
        } else {
            die("Lỗi khi di chuyển file ảnh. Kiểm tra quyền ghi và tồn tại của thư mục.");
        }
    } else {
        echo "Không có tệp được tải lên.";
    }
}

?>