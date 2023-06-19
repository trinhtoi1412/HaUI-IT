using Onthi2.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace Onthi2
{
    /// <summary>
    /// Interaction logic for Window1.xaml
    /// </summary>
    public partial class Window1 : Window
    {
        public Window1()
        {
            InitializeComponent();
        }
        QlbanHang2Context db = new QlbanHang2Context();
        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            var load = from sp in db.SanPhams
                       join loaisp in db.LoaiSps
                       on sp.MaLoai equals loaisp.MaLoai
                       join hdct in db.HoaDonChiTiets on sp.MaSp equals hdct.MaSp
                       select new
                       {
                           MaSp = sp.MaSp,
                           TenSp = sp.TenSp,
                           TenLoai = loaisp.TenLoai,
                           SoLuongBan = hdct.SoLuongMua,
                           TongTien = hdct.SoLuongMua * sp.DonGia,
                       };
            data.ItemsSource = load.ToList();
        }
    }
}
