<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<meta http-equiv="X-UA-Compatible" content="IE=edge">
	<title></title>
	<link rel="stylesheet" href="">
</head>
<body>
	<?php
	   $kn = mysqli_connect('localhost','root','12345678','quản lý nhân viên');
	   if(!$kn){
	   	echo "Lỗi kết nối!";
	   }
	   $manv = $_GET['id'];
	   $sql = "delete from ql_nhanvien where manv='$manv'";
       $kq = mysqli_query($kn,$sql) or die("Lỗi truy vấn!");
       header("location:hienthi.php");
	?>
</body>
</html>