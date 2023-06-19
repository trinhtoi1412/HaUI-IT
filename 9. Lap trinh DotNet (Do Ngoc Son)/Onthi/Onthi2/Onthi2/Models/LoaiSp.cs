using System;
using System.Collections.Generic;

namespace Onthi2.Models;

public partial class LoaiSp
{
    public string MaLoai { get; set; } = null!;

    public string? TenLoai { get; set; }

    public virtual ICollection<SanPham> SanPhams { get; } = new List<SanPham>();
}
