#pragma once

//Class LogicBattleManager
#define LogicBattleManager_GetBattleState (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "LogicBattleManager", "GetBattleState")

int GetBattleState(void* instance) {
	return reinterpret_cast<int(__fastcall *)(void*)>(LogicBattleManager_GetBattleState)(instance);
}

//Class SystemData
#define SystemData_m_uiID (uintptr_t) Il2CppGetStaticFieldOffset("Assembly-CSharp.dll","","SystemData","m_uiID")

#define SystemData_GetBattlePlayerInfo (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "SystemData", "GetBattlePlayerInfo")

//Class SystemData.RoomData
#define SystemData_RoomData_iCamp (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", "iCamp")
#define SystemData_RoomData__sName (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", "_sName")
#define SystemData_RoomData__steamSimpleName (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", "_steamSimpleName")
#define SystemData_RoomData__steamName (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", "_steamName")
#define SystemData_RoomData_uiRankLevel (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", "uiRankLevel")
#define SystemData_RoomData_iMythPoint (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", "iMythPoint")
#define SystemData_RoomData_heroid (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", "heroid")
#define SystemData_RoomData_summonSkillId (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", "summonSkillId")
#define SystemData_RoomData_lUid (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", "lUid")
#define SystemData_RoomData_uiZoneId (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", "uiZoneId")

//Class Camera
#define Camera_get_main (uintptr_t) Il2CppGetMethodOffset("UnityEngine.dll", "UnityEngine", "Camera", "get_main")
#define Camera_WorldToScreenPoint (uintptr_t) Il2CppGetMethodOffset("UnityEngine.dll", "UnityEngine", "Camera", "WorldToScreenPoint", 1)
#define Camera_get_fieldOfView (uintptr_t) Il2CppGetMethodOffset("UnityEngine.dll", "UnityEngine", "Camera", "get_fieldOfView")
#define Camera_set_fieldOfView (uintptr_t) Il2CppGetMethodOffset("UnityEngine.dll", "UnityEngine", "Camera", "set_fieldOfView", 1)

void *get_main() {
	return reinterpret_cast<void *(__fastcall *)()>(Camera_get_main)();
}

Vector3 WorldToScreen(Vector3 position) {
	return reinterpret_cast<Vector3(__fastcall *)(void *, Vector3)>(Camera_WorldToScreenPoint)(get_main(), position);
}

float get_fieldOfView() {
	return reinterpret_cast<float(__fastcall *)(void *)>(Camera_get_fieldOfView)(get_main());
}

void *set_fieldOfView(float value) {
	return reinterpret_cast<void *(__fastcall *)(void *, float)>(Camera_set_fieldOfView)(get_main(), value);
}

//Class Transform
#define Transform_get_position (uintptr_t) Il2CppGetMethodOffset("UnityEngine.dll", "UnityEngine", "Transform", "get_position")

class Transform {
public:
    Vector3 get_position() {
        auto get_position = (Vector3 (*)(Transform *)) (Transform_get_position);
        return get_position(this);
    }
};

//Class BattleBridge
#define BattleBridge_bStartBattle (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "BattleBridge", "bStartBattle")

#define BattleBridge_SetMapEntityIconPos (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "BattleBridge", "SetMapEntityIconPos", 3)
#define BattleBridge_SetMapInvisibility (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "BattleBridge", "SetMapInvisibility", 3)
#define BattleBridge_SetBloodInvisibility (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "BattleBridge", "SetBloodInvisibility", 5)
#define BattleBridge_SynBloodAttr (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "BattleBridge", "SynBloodAttr", 2)
#define BattleBridge_UpdateBloodPos (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "BattleBridge", "UpdateBloodPos", 2)

//Class BattleManager
#define BattleManager_m_LocalPlayerShow (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "BattleManager", "m_LocalPlayerShow")
#define BattleManager_m_ShowPlayers (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "BattleManager", "m_ShowPlayers")
#define BattleManager_m_ShowMonsters (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "BattleManager", "m_ShowMonsters")
#define BattleManager__RunBullets (uintptr_t) Il2CppGetStaticFieldOffset("Assembly-CSharp.dll", "", "BattleManager", "_RunBullets")

#define BattleManager_Update (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "BattleManager", "Update")

//Class ShowEntity
#define ShowEntity__Position (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "ShowEntity", "_Position")
#define ShowEntity_m_RoleName (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "ShowEntity", "m_RoleName")
#define ShowEntity__logicFighter (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "ShowEntity", "_logicFighter")
#define ShowEntityUpdateEyeLayer (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "ShowEntity","UpdateEyeLayer", 2)

//Class EntityBase
#define EntityBase_m_bSameCampType (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", "EntityBase", "m_bSameCampType")
#define EntityBase_m_IsDeathProgress (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", "EntityBase", "m_IsDeathProgress")
#define EntityBase_m_bDeath (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", "EntityBase", "<m_bDeath>k__BackingField")
#define EntityBase_canSight (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", "EntityBase", "canSight")
#define EntityBase_m_Hp (uintptr_t)  Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", "EntityBase", "m_Hp")
#define EntityBase_m_HpMax (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", "EntityBase", "m_HpMax")
#define EntityBase_m_ID (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", "EntityBase", "m_ID")
#define EntityBase_m_uGuid (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", "EntityBase", "m_uGuid")
#define EntityBase_m_Level (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", "EntityBase", "m_Level")

//Class ShowPlayer
#define ShowPlayer_m_HeroName (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "ShowPlayer", "m_HeroName")

//Class LogicFighter
#define LogicFighter_m_SkillComp (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", "LogicFighter", "m_SkillComp")

//Class LogicPlayer
#define LogicPlayer_m_KillWildTimes (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", "LogicPlayer", "m_KillWildTimes")

//Class LogicSkillComp
#define LogicSkillComp_m_CoolDownComp (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", "LogicSkillComp", "m_CoolDownComp")

//Class CoolDownComp
#define CoolDownComp_m_DicCoolInfo (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", "CoolDownComp", "m_DicCoolInfo")

#define CoolDownData_GetCoolTime (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "Battle", "CoolDownData", "GetCoolTime")

//Class ShowUnitAIComp
#define ShowUnitAIComp_Update (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "Battle", "ShowUnitAIComp", "Update")
#define ShowUnitAIComp_TryUseSkill (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "Battle", "ShowUnitAIComp", "TryUseSkill", 9)

//Class Bullet
#define Bullet_m_Id (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", "Bullet", "m_Id")
#define Bullet_m_Target (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", "Bullet", "m_Target")
#define Bullet_transform (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", "Bullet", "transform")

//Assembly-CSharp.dll -> Class LogicBattleEndCtrl
#define Offsets_LogicBattleEndCtrl_get_logicBattleManager (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "LogicBattleEndCtrl", "get_logicBattleManager")

//Assembly-CSharp.dll -> Class LogicBattleManager
#define Offsets_LogicBattleManager_GetPlayerRealSelf (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "LogicBattleManager", "GetPlayerRealSelf")

void *N_LogicBattleManager(void *instance) {
    return reinterpret_cast<void * (__fastcall *)(void *)>(Offsets_LogicBattleEndCtrl_get_logicBattleManager)(instance);
}

void *N_GetPlayerRealSelf(void *instance) {
    return reinterpret_cast<void * (__fastcall *)(void *)>(Offsets_LogicBattleManager_GetPlayerRealSelf)(instance);
}


