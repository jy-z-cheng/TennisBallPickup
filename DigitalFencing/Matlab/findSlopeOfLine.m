function lineIndices = findSlopeOfLine(point1, point2)
% This function takes two coordinates of two points as input to
% output a line function in the form of a * y = m * x + b
% Coefficient a is added to allow the description of vertical lines

% Indices
X_INDEX = 1;
Y_INDEX = 2;

% Message
message = [];

% Variables
a = 0;
b = 0;
m = 0;

%Main logic
dx = point2(X_INDEX) - point1(X_INDEX);
dy = point2(Y_INDEX) - point1(Y_INDEX);

if (dx == 0)
    b = - point2(X_INDEX);
    a = 0;
    m = 1;
    message = ['x = ', num2str(-b)];
elseif (dy == 0)
    b = point2(Y_INDEX);
    a = 1;
    m = 0;
    message = ['y = ', num2str(b)];
else
    m = dy / dx;
    a = 1;
    b = point2(Y_INDEX) - m * point2(X_INDEX);
    message = ['y = ', num2str(m), ' * x + ', num2str(b)];
end

disp(message);

lineIndices = [a m b];

end