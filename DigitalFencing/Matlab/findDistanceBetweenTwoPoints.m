function distance = findDistanceBetweenTwoPoints(point1, point2)
X = 1;
Y = 2;


distance = sqrt((point1(X) - point2(X))^2 + (point1(Y) - point2(Y))^2);

end