function distance = findShortestDistanceToLine(point, line)

closestPoint = findClosestPointToLine(point, line);

distance = findDistanceBetweenTwoPoints(point, closestPoint);

end