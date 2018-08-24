using System;

namespace Pke.Algorithms.Geometry.Planar.Models
{
    public class CrossProduct
    {
        private readonly Coordinate _p1;
        private readonly Coordinate _p2;
        private readonly Coordinate _p3;

        private readonly double _value;

        public CrossProduct(Coordinate p1, Coordinate p2, Coordinate p3)
        {
            _p1 = p1 ?? throw new ArgumentNullException(nameof(p1));
            _p2 = p2 ?? throw new ArgumentNullException(nameof(p2));;
            _p3 = p3 ?? throw new ArgumentNullException(nameof(p3));;

            _value = (_p2.X - _p1.X) * (_p3.Y - _p1.Y) - (_p2.Y - _p1.Y) * (_p3.X - _p1.X);
        }

        public double Value => _value;

        public static implicit operator double(CrossProduct crossProduct)
        {
            return crossProduct.Value;
        }
    }
}
