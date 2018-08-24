using Pke.Algorithms.Geometry.Planar.Models;

namespace Pke.Algorithms.Geometry.Planar
{
    public static class CoordinateTransforms
    {
        public static (double x, double y) ToVector(this Coordinate p1, Coordinate p2)
        {
            return (x: p2.X - p1.X, y: p2.Y - p1.Y);
        }
    }
}
