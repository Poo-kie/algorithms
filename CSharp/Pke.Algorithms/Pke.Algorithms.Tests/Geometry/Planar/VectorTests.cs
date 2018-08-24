using System;
using Pke.Algorithms.Geometry.Planar.Models;
using Xunit;

namespace Pke.Algorithms.Tests.Geometry.Planar
{
    public class VectorTests
    {
        [Fact]
        public void X_ShouldRepresentDifferenceOfXCoordinates()
        {
            var c1 = new Coordinate(1, 0);
            var c2 = new Coordinate(23, 6);

            var v = new Vector(c1, c2);

            Assert.Equal(22, v.X);
        }

        [Fact]
        public void Y_ShouldRepresentDifferenceOfYCoordinates()
        {
            var c1 = new Coordinate(1, 0);
            var c2 = new Coordinate(23, 6);

            var v = new Vector(c1, c2);

            Assert.Equal(6, v.Y);
        }

        [Fact]
        public void Magnitude_ShouldRepresentMagnitudeOfAffineCoordinates()
        {
            var c1 = new Coordinate(1, 0);
            var c2 = new Coordinate(23, 6);

            var v = new Vector(c1, c2);

            var magnitude = Math.Sqrt(Math.Pow(22, 2) + Math.Pow(6, 2));

            Assert.Equal(magnitude, v.Magnitude);
        }
    }
}
