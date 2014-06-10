function closestPoint = findClosestPointToLine(point, line)
% http://math.ucsd.edu/~wgarner/math4c/derivations/distance/distptline.htm

% Indices
X_INDEX = 1;
Y_INDEX = 2;

A_INDEX = 1;
M_INDEX = 2;
B_INDEX = 3;

% Local variables for calculations
x1 = point(X_INDEX);
y1 = point(Y_INDEX);

a = line(A_INDEX);
b = line(B_INDEX);
m = line(M_INDEX);

x0 = 0;
y0 = 0;

% Calculations
if (a == 0)
    x0 = -b;
    y0 = y1;
else
    x0 = (m * y1 + x1 - m * b) / (m*m + 1);
    y0 = (m*m*y1 + m*x1 + b) / (m*m + 1);
end

closestPoint = [x0, y0];

end