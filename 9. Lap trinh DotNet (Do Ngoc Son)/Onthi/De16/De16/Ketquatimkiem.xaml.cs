using De16.Models;
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

namespace De16
{
    /// <summary>
    /// Interaction logic for Ketquatimkiem.xaml
    /// </summary>
    public partial class Ketquatimkiem : Window
    {
        QuanLySanPhamDBContext db = new QuanLySanPhamDBContext();
        public Ketquatimkiem()
        {
            InitializeComponent();
        }

        private void window_load(object sender, RoutedEventArgs e)
        {
            var lsSP = db.SanPhams.Where(p => p.TienBan > 500000).ToList();
            data.ItemsSource = lsSP;
        }
    }
}
