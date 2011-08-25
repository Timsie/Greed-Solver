#include <iostream>
#include <cstdlib>

class GreedNode
{
    enum Direction
    {
        ABOVE,
        BELOW,
        LEFT,
        RIGHT
    };

    struct Location
    {
        unsigned short int x;
        unsigned short int y;
    };
    
    public:
        GreedNode();

        GreedNode(unsigned short int id, unsigned short int parentId);


    private:
        unsigned short int m_clearedMatrix [22,80];
        
        Direction m_dirCameFrom;

        Location m_location;

        unsigned short int m_id;
        
        unsigned short int m_parentId;

        bool m_lastNode;
};
