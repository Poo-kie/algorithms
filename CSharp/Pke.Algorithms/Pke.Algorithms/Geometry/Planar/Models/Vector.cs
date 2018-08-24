using System;

namespace Pke.Algorithms.Geometry.Planar.Models
{
    public class Vector : IEquatable<Vector>
    {
        private readonly Coordinate _a;
        private readonly Coordinate _b;

        private readonly double _x;
        private readonly double _y;

        private readonly double _magnitude;

        public Vector(Coordinate a, Coordinate b)
        {
            _a = a;
            _b = b;

            _x = _b.X - _a.X;
            _y = _b.Y - _a.Y;

            _magnitude = Math.Sqrt(Math.Pow(_x, 2) + Math.Pow(_y, 2));
        }

        public Coordinate A => _a;
        public Coordinate B => _b;

        public double Magnitude => _magnitude;

        public double X => _x;
        public double Y => _y;

        public static implicit operator (Coordinate x, Coordinate y) (Vector vector)
        {
            return (x: vector.A, y: vector.B);
        }

        public static implicit operator Vector((Coordinate x, Coordinate y) vector)
        {
            return new Vector(vector.x, vector.y);
        }

        public bool Equals(Vector other)
        {
            return _a.Equals(other.A) && _b.Equals(other.B);
        }
    }
}
