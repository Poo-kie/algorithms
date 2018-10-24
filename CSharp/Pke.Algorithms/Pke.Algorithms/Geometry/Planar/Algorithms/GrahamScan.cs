using System.Collections.Generic;
using System.Linq;
using Pke.Algorithms.Geometry.Planar.Models;

namespace Pke.Algorithms.Geometry.Planar.Algorithms
{
    public class GrahamScan : IFilterCoordinates<ConvexHull>
    {
        public ConvexHull Execute(IEnumerable<Coordinate> coordinates)
        {
            var arr = coordinates as Coordinate[] ?? coordinates.ToArray();
            var preparedPoints = arr.WithLowestLeftmostCoordinateAtHead()
                                    .SortByAngleWithHeadAsc();

            var convexHull = new ConvexHull();

            convexHull.Push(preparedPoints[0]);
            convexHull.Push(preparedPoints[1]);
            convexHull.Push(preparedPoints[2]);

            for (var i = 3; i < preparedPoints.Length; i ++)
            {
                if (new CrossProduct(convexHull.Top, convexHull.NextToTop, preparedPoints[i]).ToDirection() != Direction.Left)
                    convexHull.Pop();

                convexHull.Push(preparedPoints[i]);    
            }

            return convexHull;
        }
    }
}
