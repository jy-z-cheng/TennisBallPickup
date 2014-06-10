close all;

%%
TOP = 1;
RIGHT = 2;
BOTTOM = 3;
LEFT = 4;

STEPSIZE = 0.5;

% Simulation time
Tmax = 1000;
T = 0:Tmax;

% Environment Info
fence = [-3, 12; 22, 7; 20, 0; 4, 0];

% Robot Info
pos_robot = [round(rand*30)-5 round(rand*20)-5];
heading_robot = rand*2*pi;

%% Determine border line equations
borders = [];
bordersHeading=[];

for ind = 1:4
    nextInd = ind + 1;
    if nextInd > 4
        nextInd = 1;
    end
    borders = [borders; findSlopeOfLine(fence(ind,:), fence(nextInd,:))];
end

midpoint = sum(fence)/4;

%%

for t=T
    
    %% DigitalFencing
    borderCheck = verifyIfRobotInZone(pos_robot, borders);
    
    if ( sum(borderCheck) == 4 )
        
        % Random patrol, only used for global-local combination
        %{
        distanceToBorder = zeros(4,1);
        for ind=1:4
            distanceToBorder(ind) = findShortestDistanceToLine(pos_robot, borders(ind,:));
        end
        [val minInd] = min(distanceToBorder);
        
        if (val < 0.5)
            randomVariance = rand*pi/4;
            
            heading_robot = heading_robot+randomVariance;
            %break;
            %if (minInd ==TOP)
        end
        %}
    elseif ( sum(borderCheck) == 2 )
        heading_robot = findHeading(pos_robot, midpoint);
    elseif ( sum(borderCheck) == 3 )
        violatedBorder = borders(find(borderCheck==0),:);
        pointOfInterest = findClosestPointToLine(pos_robot, violatedBorder);
        heading_robot = findHeading(pos_robot, pointOfInterest);
        
        %plot(pointOfInterest(1), pointOfInterest(2),'ko');
    end
    
    pos_robot(1) = pos_robot(1) + STEPSIZE*cos(heading_robot);
    pos_robot(2) = pos_robot(2) + STEPSIZE*sin(heading_robot);

    %% Draw

    drawFence = [fence; fence(1,:)];

    figure(1)
    grey = [0.75,0.75,0.75];
    plot(drawFence(:,1), drawFence(:,2),'Color',grey);
    hold on
    plot(pos_robot(1), pos_robot(2),'bo');
    axis ([-5 25 -5 15])
    hold off
end