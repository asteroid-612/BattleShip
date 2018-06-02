#include "Map.h"
#include "CommonDefine.h"

Map::Map(){
    // memset 사용하는것 
    // memset(m_Data, DATA_NONE, sizeof(m_Data)); 이렇게 써도 밑의 for문과 똑같음
    
    for(int i =0; i<MAP_SIZE; ++i)
    {
        for(int j=0; j< MAP_SIZE; ++j)
        {
            m_Data[i][j] = DATA_NONE; // 초기화!!!! 
        }
    }
    
    // 2차원이든 3차원이든 다 1차원적으로 메모리상에는 존재하므로 , 수평적.
    // m_Data[8] == m_Data[1][0]; 이다.
}

Map::~Map(){
}
