   M S B A M L   `   `   `  ����?  ;De16, Version=1.0.0.0, Culture=neutral, PublicKeyToken=nullclr-namespace:De16De16  5   	       De16.MainWindow   5   	   W SPresentationCore, Version=6.0.2.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35\ XPresentationFramework, Version=6.0.2.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35e aSystem.Windows.Controls.Ribbon, Version=6.0.2.0, Culture=neutral, PublicKeyToken=b77a5c561934e089R NWindowsBase, Version=6.0.2.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35F 9http://schemas.microsoft.com/winfx/2006/xaml/presentation     5   	   R NSystem.Xaml, Version=6.0.2.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   @d2http://schemas.microsoft.com/expression/blend/2008     5   	   Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5   	   $localclr-namespace:De16     5   	   -   5          � Title$  
MainWindow��5   	   $	��450��6   $	��800��6)   .��5
      �  � 	Resources 5   
    �� 
TargetType �� Property �� Value �� 
TargetType=  7System.Windows.Controls.Primitives.DataGridColumnHeader��%�  '��       '��      '  �    �� 5      " ��6   .�5      ��  � ��$ Time New Roman)�6/   6H   �� 5       � ��
 � � �6?   5      �� 5      " ��6   .�5      ��  � ��$	 100��6*   68   �� 5       � ��$ 35��6+   68   �� 5       � �� 5      �� 5      " ��6*   .R�5      � .+�5   "   A� 
����� �6*   �� 5   "   $��Center=�63   $��Center=�6P   5      5      5      5      �� 5      "  6   .�5      ��  � ��$
 Bold"�6/   6>   �� 5        �@��TextAlignment$ Center=�6<   6M   �� 5!       � ��$ Center=�6?   6P   5"      5#      .+�5$   
   �� $��Mã sản phẩm��6   $
��Left=�6&   $��	50,30,0,0q�6A   $	��Top=�6T   �� 5%   
   -   5        $��txt_masp��5%      $
��Left=�6"   $��
200,30,0,0q�6=    �� TextWrapping$
 Wrap=�6Q   $�� ��6e   $	��Top=�6m   $	��120��6�   �� 5&   
   $��Tên sản phẩm��6   $
��Left=�6'   $��	50,70,0,0q�6B   $	��Top=�6U   �� 5'   
   -   5        $��	txt_tensp��5'      $
��Left=�6#   $��
200,70,0,0q�6>   $
 Wrap=�6R   $�� ��6f   $	��Top=�6n   $	��120��6�   �� 5(   
   $��
Đơn giá��6   $
��Left=�6"   $��
50,110,0,0q�6=   $	��Top=�6Q   �� 5)   
   -   5        $��
txt_dongia��5)      $
��Left=�6$   $��200,110,0,0q�6?   $
 Wrap=�6T   $�� ��6h   $	��Top=�6p   $	��120��6�   �� 5*   
   $��Số lượng bán��6   $
��Left=�6'   $��
50,150,0,0q�6B   $	��Top=�6V   �� 5+   
   -   5        $��txt_soluong��5+      $
��Left=�6%   $��200,150,0,0q�6@   $
 Wrap=�6U   $�� ��6i   $	��Top=�6q   $	��120��6�   �� 5,   
   $��Nhóm hàng��6   $
��Left=�6$   $��
50,190,0,0q�6?   $	��Top=�6S   �� 5-   
   -   5        $��cbonhomhang��5-      $
��Left=�6&   $��200,190,0,0q�6A   $	��Top=�6V   $	��120��6n   &   System.Windows.Controls.DataGrid  5.   
   -   5          Name$
 data��5.      $��50,230,200,100q�6!      AlternatingRowBackground
 �����	   AutoGenerateColumns$	 False��50      
   CanUserAddRows$
 False��51         Columns 53      0  *System.Windows.Controls.DataGridTextColumn  54      ,  &System.Windows.Controls.DataGridColumn   Header$ Mã SP��6%      Width5  /System.Windows.Controls.DataGridLengthConverter$ 80 6M   1  +System.Windows.Controls.DataGridBoundColumn   Binding 64   �� *MaSp+6M     55      $ Tên SP��6%   $ 80 6T    65   �� *
TenSanPham+6T     56      $ 
Đơn giá��6%   $ 80 6Q    66   �� *DonGia+6Q     57      $ Số lượng bán��6%   $	 100 6Z    6;   �� *
SoLuongBan+6Z     58      $ Nhóm hàng��6%   $ 80 6W    68   �� *
MaNhomHang+6W     59      $ Tiền bán��6%   $ * 6S    67   �� *	TienBan+6S   5<      �� 5=   
   -   5         ��Name$ butThem��5=      $��Thêm��6"   $
��Left=�61   $��100,367,0,0q�6L   $	��Top=�6a   6y   �� 5>   
   -	   5        $ butSua��5>      $��Sửa��6!   $
��Left=�6/   $��300,367,0,0q�6J   $	��Top=�6_   6w   �� 5?   
   -
   5        $ butXoa��5?      $
��Xóa��6!   $
��Left=�6/   $��450,367,0,0q�6J   $	��Top=�6_   6w   �� 5@   
   -   5        $ butTim��5@      $
��Tìm��6!   $
��Left=�6/   $��600,367,0,0q�6J   $	��Top=�6_   6w   5B      5C      