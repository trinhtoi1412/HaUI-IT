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
using De16.Models;
using Microsoft.EntityFrameworkCore;

namespace De16
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
        QuanLySanPhamDBContext db = new QuanLySanPhamDBContext();

        private void HienThiDL()
        {

            var dl = db.SanPhams.Where(sp => sp.SoLuongBan > 0).OrderByDescending(p => p.DonGia).ToList();
            data.ItemsSource = dl ?? new List<SanPham>();
        }
        private void HienThiCbo()
        {
            var query = (from nh in db.NhomHangs
                         select nh);
            cbonhomhang.ItemsSource = query.ToList();
            cbonhomhang.DisplayMemberPath = "TenNhomHang";
            cbonhomhang.SelectedValuePath = "MaNhomHang";
            cbonhomhang.SelectedIndex = 0;

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
                    txt_dongia.Text = p[2].GetValue(data.SelectedValue).ToString();
                    txt_soluong.Text = p[3].GetValue(data.SelectedValue).ToString();
                    cbonhomhang.SelectedValue = p[5].GetValue(data.SelectedValue).ToString();
                    
                }
                catch(Exception ex)
                {
                    MessageBox.Show("Có lỗi khi chọn sản phẩm" + ex.Message, "Thông báo");
                }
            }
        }

        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            HienThiCbo();
            HienThiDL();
        }
        private bool check()
        {
            if (string.IsNullOrWhiteSpace(txt_dongia.Text) || string.IsNullOrEmpty(txt_soluong.Text) 
                || string.IsNullOrEmpty(txt_tensp.Text) || string.IsNullOrEmpty(txt_masp.Text))
                return false;
            return true;
        }
        private void butThem_Click(object sender, RoutedEventArgs e)
        {
            if (!check())
            {
                MessageBox.Show("Khong duoc bo trong truong du lieu");
                return;
            }
            var spham = db.SanPhams.Any(p => p.MaSp == int.Parse(txt_masp.Text));
            if (spham == true)
            {
                MessageBox.Show("Id san pham khong duoc trung");
                return;
            }
            if (int.Parse(txt_soluong.Text) <= 0)
            {
                MessageBox.Show("So luong phai lon hon 0.");
                return;
            }
            var sp = new SanPham { 
                MaSp = int.Parse(txt_masp.Text),
                TienBan = int.Parse(txt_soluong.Text) * double.Parse(txt_dongia.Text),
                TenSanPham = txt_tensp.Text,
                DonGia = double.Parse(txt_dongia.Text),
                SoLuongBan = int.Parse(txt_soluong.Text),
                MaNhomHang = ((NhomHang)cbonhomhang.SelectedItem).MaNhomHang
            };
            try
            {
                db.SanPhams.Add(sp);
                db.SaveChanges();
                data.ItemsSource = db.SanPhams.ToList();
            }
            catch(Exception ex) { }
            {
                MessageBox.Show("Loi khi them san pham");
            }
        }
        private void butSua_Click(object sender, RoutedEventArgs e)
        {
            var sp = db.SanPhams.Where(p => p.MaSp == int.Parse(txt_masp.Text)).FirstOrDefault();

            if(sp == null)
            {
                MessageBox.Show("Khong tim thay san pham.");
                return;
            }

            sp.TenSanPham = txt_tensp.Text;
            sp.TienBan = int.Parse(txt_soluong.Text) * double.Parse(txt_dongia.Text);
            sp.TenSanPham = txt_tensp.Text;
            sp.DonGia = double.Parse(txt_dongia.Text);
            sp.SoLuongBan = int.Parse(txt_soluong.Text);
            sp.MaNhomHang = ((NhomHang)cbonhomhang.SelectedItem).MaNhomHang;
            try
            {
                db.SanPhams.Update(sp);
                db.SaveChanges();
                data.ItemsSource = db.SanPhams.ToList();
                MessageBox.Show("Sua thanh cong");
                return;
            }
            catch (Exception ex) { }
            {
                
            }
        }

        private void butXoa_Click(object sender, RoutedEventArgs e)
        {
            var sp = db.SanPhams.Where(p => p.MaSp == int.Parse(txt_masp.Text)).FirstOrDefault();
            if (sp == null)
            {
                MessageBox.Show("Khong tim thay san pham.");
                return;
            }
            try
            {
                db.SanPhams.Remove(sp);
                db.SaveChanges();
                data.ItemsSource = db.SanPhams.ToList();
                MessageBox.Show("Xoa thanh cong");
                return;
            }
            catch (Exception ex) { }
            {

            }
        }

        private void butTim_Click(object sender, RoutedEventArgs e)
        {
            var a = new Ketquatimkiem();
            a.Show();
        }
    }
}
