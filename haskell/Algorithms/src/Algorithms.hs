module Algorithms
    ( grahamScan
    ) where

data Direction = Direction {
        isLeft     :: Bool,
        isRight    :: Bool,
        isStraight :: Bool
    } deriving (Eq, Show)

getDirections (a:xs)
    |   null xs || null (tail xs)   = []
    |   crossProduct > 0            = leftDirection : getDirections (b:remainingItems)
    |   crossProduct == 0           = straightDirection : getDirections (b:remainingItems)
    |   crossProduct < 0            = rightDirection : getDirections (b:remainingItems)
            where   b = head xs
                    c = head (tail xs)
                    remainingItems = tail (tail xs)
                    crossProduct = (fst b - fst a) * (snd c - snd a) - (snd b - snd a) * (fst c - fst a)
                    leftDirection = Direction { isLeft = True, isRight = False, isStraight = False }
                    rightDirection = Direction { isLeft = False, isRight = True, isStraight = False }
                    straightDirection = Direction { isLeft = False, isRight = False, isStraight = True }

getDirections [] = []

swapHeadWithLowestPoint (x:xs) = glp xs x []
    where   glp (y:ys) z lst
                |   snd y > snd z                       = glp ys z (y:lst)
                |   snd y == snd z && fst y >= fst z    = glp ys z (y:lst)
                |   otherwise                           = glp ys y (z:lst)
            glp [] a b = a : b

xVector a b = fst b - fst a
yVector a b = snd b - snd a

vectorize a b = (xVector a b, yVector a b)

dotProduct vector1 vector2 = fst vector1 * fst vector2 + snd vector1 * snd vector2

magnitude vector = sqrt ( fst vector ^ 2 + snd vector ^ 2 )

-- sorts by angle desc with head coordinate
sortByAngleAscWithHead (lp:as) =
    lp : sortIteration as
        where sortIteration (b:bs)
                | b:bs == innerSort (b:bs)  = b : bs
                | otherwise                 = sortIteration (innerSort (b:bs))
                    where innerSort (c:cs)
                            |   null cs                                                     = [c]
                            |   cosOfAngle (vectorize lp c) < cosOfAngle (vectorize lp p2)  = c : innerSort (p2: tail cs)
                            |   otherwise                                                   = p2 : innerSort (c: tail cs)
                                    where   p2 = head cs
                                            rv = vectorize (fst lp - 1, snd lp) lp
                                            cosOfAngle v = dotProduct rv v / (magnitude rv * magnitude v)


pop = init
push x xs = xs ++ [x]

grahamScan (a:xs) =
    let sortedPoints = sortByAngleAscWithHead (swapHeadWithLowestPoint (a:xs))
        p1 = head sortedPoints
        p2 = head (tail sortedPoints)
        p3 = head (tail (tail sortedPoints))
        stack = [p1, p2, p3]
        remainingItems = snd (splitAt 3 sortedPoints)
    in if null remainingItems
        then stack
        else scan stack remainingItems
            where   scan (s:ss) [] = s : ss
                    scan (s:ss) (x:xs)
                        | isLeft (head (getDirections [top, nextToTop, x]))    = scan (push x (s:ss)) xs
                        | otherwise                                            = scan lastRemoved (x:xs)
                            where   top                 = last (s:ss)
                                    nextToTop           = last (pop (s:ss))
                                    lastRemoved         = pop (s:ss)
