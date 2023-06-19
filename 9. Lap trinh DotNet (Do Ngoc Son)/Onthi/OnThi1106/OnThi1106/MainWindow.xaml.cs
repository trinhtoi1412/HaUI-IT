using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Text.RegularExpressions;
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
using OnThi1106.Models;


namespace OnThi1106
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
        QuanLyBenhNhanDBContext db = new QuanLyBenhNhanDBContext();
        private void data_SelectedCellsChanged(object sender, SelectedCellsChangedEventArgs e)
        {
            if (dgvBenhNhan.SelectedItem != null)
            {
                try
                {
                    Type t = dgvBenhNhan.SelectedItem.GetType();
                    PropertyInfo[] p = t.GetProperties();
                    txt_mabn.Text = p[0].GetValue(dgvBenhNhan.SelectedValue).ToString();
                    txt_hoten.Text = p[1].GetValue(dgvBenhNhan.SelectedValue).ToString();
                    txt_songay.Text = p[2].GetValue(dgvBenhNhan.SelectedValue).ToString();
                    cbokhoakham.SelectedValue = p[3].GetValue(dgvBenhNhan.SelectedValue).ToString();
                }
                catch (Exception ex)
                {
                    MessageBox.Show("Co loi khi chon hang" + ex.Message, "Thong bao");
                }
            }

        }

        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            HienThiDL();
            HienThiCbo();
        }

        private void HienThiCbo()
        {
            var cbo = from kh in db.Khoas
                      select kh;
            cbokhoakham.ItemsSource = cbo.ToList();
            cbokhoakham.DisplayMemberPath = "TenKhoa";
            cbokhoakham.SelectedValuePath = "MaKhoa";
            cbokhoakham.SelectedIndex = 0;
        }
        private void HienThiDL()
        {
            var load = from bn in db.BenhNhans
                       join kh in db.Khoas
                       on bn.MaKhoa equals kh.MaKhoa
                       orderby bn.SoNgayNamVien descending
                       select new
                       {
                           bn.MaBn,
                           bn.HoTen,
                           bn.SoNgayNamVien,
                           kh.MaKhoa,
                           bn.VienPhi
                       };
            dgvBenhNhan.ItemsSource = load.ToList();
        }
        private bool check()
        {
            if (string.IsNullOrEmpty(txt_hoten.Text) || string.IsNullOrEmpty(txt_songay.Text) || string.IsNullOrEmpty(txt_mabn.Text))
                return false;
            return true;

        }
        private void butThem_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                if (!check())
                    throw new Exception("Khong duoc bo trong truong du lieu");
                if (!Regex.IsMatch(txt_mabn.Text, @"\d+"))
                    throw new Exception("Ma benh nhan khong dung kieu du lieu");
                if (!Regex.IsMatch(txt_songay.Text, @"\d+"))
                    throw new Exception("So ngay nhap vien khong dung kieu du lieu");
                if (int.Parse(txt_songay.Text) < 1)
                    throw new Exception("So ngay nam vien phai > 1");
                var bnhan = (from bn in db.BenhNhans
                             where bn.MaBn == Int32.Parse(txt_mabn.Text)
                             select bn).SingleOrDefault();

                if (bnhan != null)
                    throw new Exception("Ma benh nhan da ton tai");
                var maKhoa = (from kh in db.Khoas
                              where kh.TenKhoa == cbokhoakham.Text
                              select kh.MaKhoa).SingleOrDefault();
                BenhNhan benhnhan = new BenhNhan();
                benhnhan.MaBn = Int32.Parse(txt_mabn.Text);
                benhnhan.HoTen = txt_hoten.Text;
                benhnhan.MaKhoa = Convert.ToInt32(maKhoa);
                benhnhan.SoNgayNamVien = Int32.Parse(txt_songay.Text);
                benhnhan.VienPhi = Int32.Parse(txt_songay.Text) * 200000;
                db.BenhNhans.Add(benhnhan);
                db.SaveChanges();
                HienThiDL();
            }
            catch(Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

       

        private void butTim_Click(object sender, RoutedEventArgs e)
        {
            Window1 w = new Window1();
            w.Show();
        }
    }
}
