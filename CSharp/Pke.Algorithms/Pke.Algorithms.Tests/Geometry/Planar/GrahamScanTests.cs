using System.Collections.Generic;
using System.Linq;
using Pke.Algorithms.Geometry.Planar.Algorithms;
using Pke.Algorithms.Geometry.Planar.Models;
using Xunit;

namespace Pke.Algorithms.Tests.Geometry.Planar
{
    public class GrahamScanTests
    {
        protected IEnumerable<Coordinate> Points;
        protected IFilterCoordinates<ConvexHull> Algorithm;

        public GrahamScanTests()
        {
            Algorithm = new GrahamScan();

            Points = new[]
            {
                new Coordinate(x:  1, y: 1),  // not on convex hull
                new Coordinate(x: -5, y: 0),  // on convex hull
                new Coordinate(x:  5, y: 5),  // on convex hull
                new Coordinate(x:  2, y: 4),  // not on convex hull
                new Coordinate(x:  5, y: 0),  // on convex hull
                new Coordinate(x: -5, y: 5),  // on convex hull
            };
        }

        [Fact]
        public void GrahamScan_ShouldReturnAllPointsOnConvexHull()
        {
            var convexHull = Algorithm.Execute(Points).ToArray();

            Assert.Equal(4, convexHull.Length);

            Assert.Equal(new Coordinate( 5, 0), convexHull[0]);
            Assert.Equal(new Coordinate( 5, 5), convexHull[1]);
            Assert.Equal(new Coordinate(-5, 5), convexHull[2]);
            Assert.Equal(new Coordinate(-5, 0), convexHull[3]);
        }

        [Fact]
        public void GrahamScan_ShouldNotReturnPointsWithinTheConvexHull()
        {
            var convexHull = Algorithm.Execute(Points).ToArray();

            Assert.DoesNotContain(convexHull, pts => pts.X.AlmostEquals(1) && pts.Y.AlmostEquals(1));
            Assert.DoesNotContain(convexHull, pts => pts.X.AlmostEquals(2) && pts.Y.AlmostEquals(4));
        }
    }
}
