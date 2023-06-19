using System;
using System.Collections.Generic;

namespace Onthi2.Models;

public partial class HoaDonChiTiet
{
    public string MaHd { get; set; } = null!;

    public string MaSp { get; set; } = null!;

    public int? NgayBan { get; set; }

    public int? SoLuongMua { get; set; }

    public virtual SanPham MaSpNavigation { get; set; } = null!;
}
