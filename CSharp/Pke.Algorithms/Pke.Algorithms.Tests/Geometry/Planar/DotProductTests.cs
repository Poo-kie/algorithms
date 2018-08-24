using Pke.Algorithms.Geometry.Planar.Models;
using Xunit;

namespace Pke.Algorithms.Tests.Geometry.Planar
{
    public class DotProductTests
    {
        [Fact]
        public void Value_ShouldReturnDotProduct()
        {
            var c1 = new Coordinate(1, 0);
            var c2 = new Coordinate(23, 6);

            var c3 = new Coordinate(33, 9);
            var c4 = new Coordinate(2, 52);

            var v1 = new Vector(c1, c2);
            var v2 = new Vector(c3, c4);

            var dp = v1.X * v2.X + v1.Y * v2.Y;

            Assert.Equal(dp, new DotProduct(v1, v2));
        }
    }
}
