using Pke.Algorithms.Geometry.Planar;
using Pke.Algorithms.Geometry.Planar.Models;
using Xunit;

namespace Pke.Algorithms.Tests.Geometry.Planar
{
    public class CrossProductTransformTests
    {
        [Fact]
        public void Value_ShouldRepresentCrossProductOfGivenPoints()
        {
            var p1 = new Coordinate(0, 0);
            var p2 = new Coordinate(3, 3);
            var p3 = new Coordinate(3, 0);

            var cp = (p2.X - p1.X) * (p3.Y - p1.Y) - (p2.Y - p1.Y) * (p3.X - p1.X);

            Assert.Equal(Direction.Left, new CrossProduct(p2, p1, p3).ToDirection());
        }
    }
}
