using Onthi2.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Onthi2
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }
        QlbanHang2Context db = new QlbanHang2Context();
        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            var load = from sp in db.SanPhams
                       orderby sp.DonGia
                       select new
                       {
                           MaSp = sp.MaSp,
                           TenSp = sp.TenSp,
                           MaLoai = sp.MaLoai,
                           DonGia = sp.DonGia,
                           SoLuongCo = sp.SoLuongCo,
                           ThanhTien = sp.SoLuongCo * sp.DonGia,
                       };
            data.ItemsSource = load.ToList();
            htCombobox();
        }
        private void htCombobox()
        {
            var combo = from lsp in db.LoaiSps
                        select lsp;
            txt_loaisp.ItemsSource = combo.ToList();
            txt_loaisp.DisplayMemberPath = "TenLoai";
            txt_loaisp.SelectedValuePath = "MaLoai";
            txt_loaisp.SelectedIndex = 0;
        }

        private void data_SelectedCellsChanged(object sender, SelectedCellsChangedEventArgs e)
        {
            if(data.SelectedItem != null)
            {
                try
                {
                    Type t = data.SelectedItem.GetType();
                    PropertyInfo[] p = t.GetProperties();
                    txt_masp.Text = p[0].GetValue(data.SelectedValue).ToString();
                    txt_tensp.Text = p[1].GetValue(data.SelectedValue).ToString();
                    txt_loaisp.SelectedValue = p[2].GetValue(data.SelectedValue).ToString();
                    txt_dongia.Text = p[3].GetValue(data.SelectedValue).ToString();
                    txt_sl.Text = p[4].GetValue(data.SelectedValue).ToString();
                }
                catch(Exception ex)
                {
                    MessageBox.Show("Có lỗi khi chọn hàng " + ex.Message, "Thông báo");
                }
            }
        }

        private void btn_them_Click(object sender, RoutedEventArgs e)
        {
            var ktra = db.SanPhams.SingleOrDefault(sp => sp.MaSp == txt_masp.Text);
            if(ktra != null)
            {
                MessageBox.Show("Trùng mã sản phẩm!", "Thông báo", MessageBoxButton.OK, MessageBoxImage.Error);
                return;
            }
            else
            {
                float gia = Convert.ToSingle(txt_dongia.Text);
                int sl = Convert.ToInt32(txt_sl.Text);
                SanPham sp = new SanPham();
                sp.MaSp = txt_masp.Text;
                sp.TenSp = txt_tensp.Text;
                if(gia <=0 || sl <=0)
                {
                    MessageBox.Show("Vui lòng nhập số lượng và đơn giá > 0.", "Thông báo");
                    return;
                }
                else
                {
                    try
                    {
                        sp.DonGia = Convert.ToSingle(txt_dongia.Text);
                        sp.SoLuongCo = Convert.ToInt32(txt_sl.Text);
                    }
                    catch (Exception)
                    {
                        MessageBox.Show("Vui lòng nhập kiểu số.", "Thông báo");
                    }
                }
                LoaiSp loaisp = (LoaiSp)txt_loaisp.SelectedItem;
                sp.MaLoai = loaisp.MaLoai;
                db.SanPhams.Add(sp);
                db.SaveChanges();
                Window_Loaded(sender, e);
            }
        }

        private void btn_sua_Click(object sender, RoutedEventArgs e)
        {
            var ktra = db.SanPhams.SingleOrDefault(sp => sp.MaSp == txt_masp.Text);
            float gia = Convert.ToSingle(txt_dongia.Text);
            int sl = Convert.ToInt32(txt_sl.Text);
            if (ktra == null)
            {
                MessageBox.Show("Không tìm thấy mã sản phẩm!", "Thông báo", MessageBoxButton.OK, MessageBoxImage.Error);
                return;
            }
            else
            {
                ktra.TenSp = txt_tensp.Text;
                if (gia <= 0 || sl <= 0)
                {
                    MessageBox.Show("Vui lòng nhập số lượng và đơn giá > 0.", "Thông báo");
                    return;
                }
                else
                {
                    try
                    {
                        ktra.DonGia = gia;
                        ktra.SoLuongCo = sl;
                    }
                    catch (Exception)
                    {
                        MessageBox.Show("Vui lòng nhập kiểu số.", "Thông báo");
                    }
                }
                LoaiSp loaisp = (LoaiSp)txt_loaisp.SelectedItem;
                ktra.MaLoai = loaisp.MaLoai;
                db.SaveChanges();
                Window_Loaded(sender, e);
            }
        }

        private void btn_xoa_Click(object sender, RoutedEventArgs e)
        {
            var xoa = db.SanPhams.SingleOrDefault(sp => sp.MaSp == txt_masp.Text);
            if(xoa == null)
            {
                MessageBox.Show("Không tìm thấy mã sản phẩm!", "Thông báo");
                return;
            }
            else
            {
                MessageBoxResult result = MessageBox.Show($"Xóa sản phẩm có mã {xoa.MaSp}","Thông báo",MessageBoxButton.YesNo,MessageBoxImage.Question);
                if (result == MessageBoxResult.Yes)
                {
                    db.Remove(xoa);
                    db.SaveChanges();
                    Window_Loaded(sender, e);
                }
                else
                    return;
            }
        }

        private void btn_tim_Click(object sender, RoutedEventArgs e)
        {
            Window1 win = new Window1();
            win.Show();
        }
    }
}
