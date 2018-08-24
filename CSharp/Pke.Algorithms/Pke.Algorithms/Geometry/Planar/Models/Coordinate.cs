using System;

namespace Pke.Algorithms.Geometry.Planar.Models
{
    public class Coordinate : IEquatable<Coordinate>
    {
        private readonly double _x;
        private readonly double _y;

        public Coordinate(double x, double y)
        {
            _x = x;
            _y = y;
        }

        public double X => _x;
        public double Y => _y;

        public bool Equals(Coordinate other)
        {
            return _x.AlmostEquals(other.X) && _y.AlmostEquals(other.Y);
        }
    }
}
