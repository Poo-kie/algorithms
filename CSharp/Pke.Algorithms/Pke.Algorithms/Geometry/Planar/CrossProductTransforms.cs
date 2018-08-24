using Pke.Algorithms.Geometry.Planar.Models;

namespace Pke.Algorithms.Geometry.Planar
{
    public static class CrossProductTransforms
    {
        public static Direction ToDirection(this CrossProduct crossProduct)
        {
            return crossProduct > 0 ?
                    Direction.Left :
                     crossProduct == 0 ?
                         Direction.Straight :
                         Direction.Right;
        }
    }
}
