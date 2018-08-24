namespace Pke.Algorithms.Geometry.Planar.Models
{
    public static class Cosine
    {
        public static double FromVectors(Vector v1, Vector v2)
        {
            return new DotProduct(v1, v2) / (v1.Magnitude * v2.Magnitude);
        }
    }
}
