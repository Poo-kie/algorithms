using System;
using Pke.Algorithms.Geometry.Planar.Models;
using Xunit;

namespace Pke.Algorithms.Tests.Geometry.Planar
{
    public class CosineTests
    {   
        [Fact]
        public void FromVectors_ShouldGetCosineOfAngleBetween90DegreeVectors()
        {
            var p1 = new Coordinate(0, 0);
            var p2 = new Coordinate(3, 0);

            var p3 = new Coordinate(4, 0);
            var p4 = new Coordinate(4, 4);

            var v1 = new Vector(p1, p2);
            var v2 = new Vector(p3, p4);

            // vectors form 90 degrees
            var cos = Cosine.FromVectors(v1, v2);

            Assert.Equal(0, cos);
        }

        [Fact]
        public void FromVectors_ShouldGetCosineOfAngleBetween45DegreeVectors()
        {
            var p1 = new Coordinate(0, 0);
            var p2 = new Coordinate(3, 0);

            var p3 = new Coordinate(4, 0);
            var p4 = new Coordinate(5, 1);

            var v1 = new Vector(p1, p2);
            var v2 = new Vector(p3, p4);

            var cosOf45Degrees = Math.Cos((Math.PI / 180) * 45);

            // vectors form 90 degrees
            var cos = Cosine.FromVectors(v1, v2);

            Assert.True(cosOf45Degrees.AlmostEquals(cos));
        }
    }
}
