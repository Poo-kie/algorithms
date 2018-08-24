using System;

namespace Pke.Algorithms.Geometry.Planar.Models
{
    public class DotProduct
    {
        private readonly Vector _v1;
        private readonly Vector _v2;

        private readonly double _value;

        public DotProduct(Vector v1, Vector v2)
        {
            _v1 = v1 ?? throw new ArgumentNullException(nameof(v1));
            _v2 = v2 ?? throw new ArgumentNullException(nameof(v2));

            _value = _v1.X * _v2.X + _v1.Y * _v2.Y;
        }

        public Vector V1 => _v1;
        public Vector V2 => _v2;

        public double Value => _value;

        public static implicit operator double(DotProduct dotProduct)
        {
            return dotProduct.Value;
        }
    }
}
