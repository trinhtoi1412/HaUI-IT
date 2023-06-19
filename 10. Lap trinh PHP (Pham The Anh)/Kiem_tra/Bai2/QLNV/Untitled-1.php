<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<title>Trang hiển thị</title>
	<link rel="stylesheet" href="">
</head>
<body>
    <h2 style="text-align: center;">DANH SÁCH NHÂN VIÊN</h2>
	<?php
      $kn = mysqli_connect('localhost','root','','qlnv');
      if (!$kn) {
                echo "Kết nối thất bại";
       }
        $sql = 'select * from nhanvien';
        $kq = mysqli_query($kn,$sql);
        if (!$kq) {
        	echo "Lỗi truy vấn";
        }
        if(mysqli_num_rows($kq)>0){
        	echo '<table width="900" border="1" align="center">
        	   <tr>
        	     <td>Mã NV</td>
        	     <td>Họ tên</td>
        	     <td>Hinh Anh</td>
        	     <td>Xep Loai</td>
        	     <td>Luong Ngay</td>
        	     <td>Ngay cong</td>
                 <td>Tong luong</td>
                 <td>Thực hiện</td>
        	   </tr>';
        while ($row = mysqli_fetch_row($kq)){
             $manv = $row[0];
             $hoten = $row[1];
             $hinhanh = $row[2];
             $xeploai = $row[3];
             $luongngay = $row[4];
             $ngaycong = $row[5];
             if($xeploai=="A"){
                $tongluong =$luongngay*$ngaycong+500000;
             }else if($xeploai=="B"){
                $tongluong =$luongngay*$ngaycong+300000;
             }
             echo "<tr>";
             echo "<td>$manv</td>";
             echo "<td>$hoten</td>";
             echo "<td><img src='$hinhanh' alt='' width='100' height='100'/></td>";
             echo "<td>$xeploai</td>";
             echo "<td>$luongngay</td>";
             echo "<td>$ngaycong</td>";
             echo "<td>$tongluong</td>";
             echo "<td><a href='sua.php?MaNV=$manv'>Sửa</a> | <a href='xoa.php?id=$manv'>Xóa</a></td>";
             echo "</tr>";
          }
          echo "</table>";
        }
	?>
</body>
</html>