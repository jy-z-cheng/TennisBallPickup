function [borderCheck] = verifyIfRobotInZone(position, borders)
    TOP = 1;
    RIGHT = 2;
    BOTTOM = 3;
    LEFT = 4;

    borderCheck = zeros(4,1);
    
    robotX = position(1);
    robotY = position(2);
    
    for ind = 1:4
        a=borders(ind,1);
        m=borders(ind,2);
        b=borders(ind,3);

        %%
        if ind==TOP || ind==BOTTOM
            if m==0
                refY=b;
            else
                refY=m*robotX+b;
            end
            
            if ind==TOP
                if robotY <= refY
                    borderCheck(ind) = 1;
                end
            else
                if robotY > refY
                    borderCheck(ind) = 1;
                end
            end
            
        else
        %%
            if a==0
                refX=-b;
            else
                refX=(robotY-b)/m;
            end
            
            if ind==RIGHT
                if robotX <= refX
                    borderCheck(ind) = 1;
                end
            else
                if robotX > refX
                    borderCheck(ind) = 1;
                end
            end            
        end
    end

end