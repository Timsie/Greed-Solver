#include "GreedNode.h" 


GreedNode::GreedNode(unsigned short int id, GreedNode* parent,
                     unsigned short int numMoves, Direction dir) :
    m_id(id),
    m_numberOfMoves(numMoves),
    m_parent(parent),
    m_dirCameFrom(dir)
{
    setClearedMatrix();
}

GreedNode::~GreedNode()
{
}

greedMatrix& GreedNode::getClearedMatrix()
{
    return *m_clearedMatrix; 
}

unsigned short int GreedNode::getId()
{
    return m_id;
}

GreedNode* GreedNode::getParent()
{
    return m_parent;
}

GreedNode::Location GreedNode::getLocation()
{
    return m_location;
}

GreedNode::Direction GreedNode::getDirectionCameFrom()
{
    return m_dirCameFrom;
}

void GreedNode::setLocation(GreedNode::Location loc)
{
    m_location = loc;
}

void GreedNode::setParent(GreedNode& parent)
{
    m_parent = &parent;
}

void GreedNode::setId(unsigned short int id)
{
    m_id = id;
}

void GreedNode::setDirectionCameFrom(GreedNode::Direction dir)
{
    m_dirCameFrom = dir;
}

void GreedNode::setClearedMatrix()
{
    unsigned short int x = 0, y = 0;
    unsigned short int one = 1;
    m_clearedMatrix = &m_parent->getClearedMatrix();
    GreedNode::Location loc = m_parent->getLocation();
    switch(m_dirCameFrom)
    {
        case GreedNode::ABOVE:
            y -= m_numberOfMoves;
            for(int r=loc.y; r>loc.y-y; r--)
            {
                m_clearedMatrix->get(x,r) = one;
            }
            break;
        case GreedNode::BELOW:
            y += m_numberOfMoves;
            break;
        case GreedNode::LEFT:
            x += m_numberOfMoves;
            break;
        case GreedNode::RIGHT:
            x -= m_numberOfMoves;
            break;
    }
    loc.x += x;
    loc.y += y;
    setLocation(loc);
}
