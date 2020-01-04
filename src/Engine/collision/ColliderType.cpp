/*
 * ====================== ColliderType.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2019.11.15
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 */
#include "ColliderType.h"

//--------------- Libs ------------------//
#include "magic_enum.hpp"

//-------------------- Engine --------------------//
#include "config.h"

#include "tprDebug.h"


double Circular::radius_for_dogo { 24.0 }; // Must small than HALF_PIXES_PER_MAPENT


// 这里的 半径，是 square 在 artifactCoord 坐标系内的 半径值
// 所有 afs / gos 都要和这个值统一
// 暂时只有一个值
// 
double Square::unifiedRadius { static_cast<double>(HALF_PIXES_PER_MAPENT) }; // 32.0



ColliderType str_2_ColliderType( const std::string &name_ )noexcept{

    auto labelOP = magic_enum::enum_cast<ColliderType>(name_);
    if( labelOP.has_value() ){
        return *labelOP;
    }else{
        cout << "can't find ColliderType: " << name_ << endl;
        tprAssert(0);
        return ColliderType::Nil; // never reach
    }
}


