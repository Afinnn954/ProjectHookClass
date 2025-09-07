#pragma once

struct sAim {
    struct sHelper {
        struct sSkills {
            bool Basic;
            bool Spell;
            bool Skill1;
            bool Skill2;
            bool Skill3;
            bool Skill4;
			bool Balmond;
			bool Martis;
			bool Vonzy;
        };
        sSkills Skills{0};

        struct sPriority {
            int Target = 0;
            bool AutoTakeSword;
        };
        sPriority Priority{0};
        
        struct sAutoCombo {
            //Auto Combo 1
            bool Gusion;
			bool Gusion2;
            bool Paquito;
            bool Benedetta;
            bool Lunox1;
            bool Lunox2;
            //Autom Combo 2
            bool Tigreal;
            bool Atlas;
            bool Franco1;
            bool Lolita;
            //Auto Combo 3
            bool Selena;
            bool Badang;
            bool Saber1;
            bool Harith;
            //Auto Combo 4
            bool Brody;
            bool Franco2;
            bool Xavier;
			bool Xavier2;
			bool Xavier3;
			bool Xavier4;
            bool Saber2;
			bool Martis;
        };
        sAutoCombo AutoCombo{0};
        
        struct sMoreFeature {
            bool Chou;
			bool Chou2;
            bool Pharsa;
            bool Kimmy;
			bool Yve;
        };
        sMoreFeature MoreFeature{0};
        
        struct sAutoUltimate {
            //1
            bool Beatrix;
            bool Xavier;
			
            bool Granger;
            bool Balmond;
            //2
            bool Layla;
            bool Moskov;
            bool Nana;
            bool Gord;
            //3
            bool Hilda;
            bool Martis;
            bool Thamuz;
            bool Argus;
        };
        sAutoUltimate AutoUltimate{0};
        
        struct sAutoDefense {
            bool Executed;
            bool FlameShoot;
            bool Vengeance;
            bool Flicker;
            bool Aegis;
        };
        sAutoDefense AutoDefense{0};
        
        struct sAutoRetribution {
			bool Ling;
            bool Buff1;
			bool Buff2;
            bool Turtle;
            bool Lord;
            bool Crab;
            bool Litho;
			bool Scaled;
			bool Rockursa;
        };
                sAutoRetribution AutoRetribution{0};
		
    };
    sHelper Helper{0};
    
    Vector3 Dir = Vector3::zero();
    Vector3 Pos = Vector3::One();
    Vector3 NearestEnemyPos = Vector3::zero();
            int NearestEnemyGuid = 0;
            float NearestEnemyDist = 9999;
            bool RetriDistButton;
};
sAim Aim{0};



//static float BattleManager__RunBullets = false;
//static float Bullet_transform = false;
//static float Bullet_m_Id = false;
//static float m_ID = false;
static float TargetMyHealth = 2500;
static float RangeFOV = 10.0f;
static float TargetHP = 1000.0f;
static float TargetDistance = 3.0f;
//static float RangeFOV = 10.0f;
static float HealthHero = 500.0f;
static float Auto = 1000.0f;
static float Execute = 500.0f;
static float Argus = 1000.0f;
static float DisRet = 5.0f;


void (*orig_TryUseSkill)(...);
void TryUseSkill(void *instance, int skillId, Vector3 dir, bool dirDefault, Vector3 pos, bool bCommonAtk, bool bAuto, bool bAlong, bool bCache, bool isInFirstDragRange) {
    bool isDoneAim = false;
    if (instance != NULL) {
        float MaxDist = std::numeric_limits<float>::infinity();
        float MaxEnemyHP = std::numeric_limits<float>::infinity();
        float MaxPercentHP = std::numeric_limits<float>::infinity();
        float MaxSwordDist = std::numeric_limits<float>::infinity();
        Vector3 EntityPos = Vector3::zero();
        Vector3 SwordPos = Vector3::zero();
        void *BattleManager_Instance;
        Il2CppGetStaticFieldValue("Assembly-CSharp.dll", "", "BattleManager", "Instance", &BattleManager_Instance);
        if (BattleManager_Instance) {
            auto m_LocalPlayerShow = *(uintptr_t *) ((uintptr_t)BattleManager_Instance + BattleManager_m_LocalPlayerShow);
            if (m_LocalPlayerShow) {
				//auto m_ID = *(int *) ((uintptr_t)Pawn + Bullet_m_Id);
                auto selfPos = *(Vector3 *) ((uintptr_t)m_LocalPlayerShow + ShowEntity__Position);
                auto HeroID = *(int *) ((uintptr_t)m_LocalPlayerShow + EntityBase_m_ID);
                if (selfPos != Vector3::zero()) {
                    monoList<void **> *m_ShowPlayers = *(monoList<void **> **) ((uintptr_t)BattleManager_Instance + BattleManager_m_ShowPlayers);
                    if (m_ShowPlayers) {
                        for (int i = 0; i < m_ShowPlayers->getSize(); i++) {
                            auto Pawn = m_ShowPlayers->getItems()[i];
                            if (!Pawn) continue;
                            auto m_bSameCampType = *(bool *) ((uintptr_t)Pawn + EntityBase_m_bSameCampType);
                            if (m_bSameCampType) continue;
                            auto m_bDeath = *(bool *) ((uintptr_t)Pawn + EntityBase_m_bDeath);
                            if (m_bDeath) continue;
                            auto m_IsDeathProgress = *(bool *) ((uintptr_t)Pawn + EntityBase_m_IsDeathProgress);
                            if (m_IsDeathProgress) continue;
                            auto _Position = *(Vector3 *) ((uintptr_t)Pawn + ShowEntity__Position);
                            float Distance = (int) Vector3::Distance(selfPos, _Position);
                            float EnemyDistance = Vector3::Distance(selfPos, _Position);
                            float CurHP = *(int *) ((uintptr_t)Pawn + EntityBase_m_Hp);
                            float MaxHP = *(int *) ((uintptr_t)Pawn + EntityBase_m_HpMax);
                            float MyHealth = *(int *) ((uintptr_t)m_LocalPlayerShow + EntityBase_m_Hp);
                            float PercentHP = CurHP * 100 / MaxHP;
                            if (!m_bDeath && !m_IsDeathProgress) {
                            if (Distance < RangeFOV || EnemyDistance < TargetDistance || CurHP <= TargetHP) {
                                if (Aim.Helper.Priority.Target == 0 && Distance < MaxDist) {
                                    EntityPos = _Position;
                                    MaxDist = Distance;
                                }
                                if (Aim.Helper.Priority.Target == 1 && CurHP < MaxEnemyHP) {
                                    EntityPos = _Position;
                                    MaxEnemyHP = CurHP;
                                }
                                if (Aim.Helper.Priority.Target == 2 && PercentHP < MaxPercentHP) {
                                    EntityPos = _Position;
                                    MaxPercentHP = PercentHP;
                                }
								monoList<void **> *_RunBullets = *(monoList<void **> **) ((uintptr_t)BattleManager__RunBullets);
                    if (_RunBullets) {
                        for (int i = 0; i < _RunBullets->getSize(); i++) {
                            auto Pawn = _RunBullets->getItems()[i];
                            if (!Pawn) continue;
                            auto m_ID = *(int *) ((uintptr_t)Pawn + Bullet_m_Id);
                            if (m_ID != 8452) continue;
                            auto transform = *(Transform **) ((uintptr_t)Pawn + Bullet_transform);
                            float Distance = (int) Vector3::Distance(selfPos, transform->get_position());
                    
                            if (Distance < 5) {
                                if (Aim.Helper.Priority.AutoTakeSword && Distance < MaxSwordDist) {
                                    SwordPos = transform->get_position();
                                    MaxSwordDist = Distance;
                                }
                            }
                        }
                    }

                    if (SwordPos != Vector3::zero() && HeroID == 84) {
                        auto targetLockPos = Vector3::Normalized(SwordPos - selfPos);
                        if (skillId == 100 * HeroID + 20) {
                            isDoneAim = true;
							orig_TryUseSkill(instance, skillId, targetLockPos, dirDefault, pos, bCommonAtk, bAuto, bAlong, bCache);
                        }
                        } else if (EntityPos != Vector3::zero()) {
                                    auto iTargetPos = Vector3::Normalized(_Position - selfPos);
                                    //Auto Combo
                                    if (Aim.Helper.AutoCombo.Gusion) {
                                        if (EnemyDistance < TargetDistance && skillId == 5600) {
                                            if (_Position != Vector3::zero()) {
                                                orig_TryUseSkill(instance, 5620, iTargetPos, true, _Position, false, true);
                                                orig_TryUseSkill(instance, 5610, iTargetPos, true, _Position, false, true);
                                                if (EnemyDistance < TargetDistance && skillId == 5600) {
                                                    if (_Position != Vector3::zero()) {
                                                        orig_TryUseSkill(instance, 5630, iTargetPos, true, _Position, false, true);
                                                        orig_TryUseSkill(instance, 5620, iTargetPos, true, _Position, false, true);
                                                        orig_TryUseSkill(instance, 5610, iTargetPos, true, _Position, false, true);
                                                    }
                                                }
                                            }
                                        }
                                    }
									if (Aim.Helper.AutoCombo.Gusion2) {
                                        if (EnemyDistance < TargetDistance && skillId == 5600) {
                                            if (_Position != Vector3::zero()) {
                                                orig_TryUseSkill(instance, 5610, iTargetPos, true, _Position, false, true);
                                                orig_TryUseSkill(instance, 5620, iTargetPos, true, _Position, false, true);
                                                if (EnemyDistance < TargetDistance && skillId == 5630) {
                                                    if (_Position != Vector3::zero()) {
                                                        orig_TryUseSkill(instance, 5610, iTargetPos, true, _Position, false, true);
                                                        orig_TryUseSkill(instance, 5620, iTargetPos, true, _Position, false, true);
                                                        //orig_TryUseSkill(instance, 5600, iTargetPos, true, _Position, false, true);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (Aim.Helper.AutoCombo.Paquito) {
                                        if (EnemyDistance < TargetDistance && skillId == 10300) {
                                            if (_Position != Vector3::zero()) {
                                                orig_TryUseSkill(instance, 10320, iTargetPos, true, _Position, false, true);
                                                orig_TryUseSkill(instance, 10330, iTargetPos, true, _Position, false, true);
                                                if (EnemyDistance < TargetDistance && skillId == 10300) {
                                                    if (_Position != Vector3::zero()) {
                                                        orig_TryUseSkill(instance, 10320, iTargetPos, true, _Position, false, true);
                                                        orig_TryUseSkill(instance, 10310, iTargetPos, true, selfPos, false, true);
                                                        orig_TryUseSkill(instance, 10330, iTargetPos, true, _Position, false, true);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (Aim.Helper.AutoCombo.Benedetta) {
                                        if (EnemyDistance < TargetDistance && skillId == 9700) {
                                            if (_Position != Vector3::zero()) {
                                                orig_TryUseSkill(instance, 9720, iTargetPos, true, _Position, false, true);
                                                orig_TryUseSkill(instance, 9710, iTargetPos, true, _Position, false, true);
                                                if (EnemyDistance < TargetDistance && skillId == 9700) {
                                                    if (_Position != Vector3::zero()) {
                                                        orig_TryUseSkill(instance, 9730, iTargetPos, true, _Position, false, true);
                                                        orig_TryUseSkill(instance, 9700, iTargetPos, true, _Position, false, true);
                                                        orig_TryUseSkill(instance, 9700, iTargetPos, true, _Position, false, true);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (Aim.Helper.AutoCombo.Lunox1) {
                                        if (EnemyDistance < TargetDistance && skillId == 6800) {
                                            if (_Position != Vector3::zero()) {
                                                orig_TryUseSkill(instance, 6830, iTargetPos, true, _Position, false, true);
                                                orig_TryUseSkill(instance, 6840, iTargetPos, true, _Position, false, true);
                                                if (EnemyDistance < TargetDistance && skillId == 6800) {
                                                    if (_Position != Vector3::zero()) {
                                                        orig_TryUseSkill(instance, 6810, iTargetPos, true, _Position, false, true);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (Aim.Helper.AutoCombo.Lunox2) {
                                        if (EnemyDistance < TargetDistance && skillId == 6800) {
                                            if (_Position != Vector3::zero()) {
                                                orig_TryUseSkill(instance, 6840, iTargetPos, true, _Position, false, true);
                                                orig_TryUseSkill(instance, 6830, iTargetPos, true, _Position, false, true);
                                                if (EnemyDistance < TargetDistance && skillId == 6800) {
                                                    if (_Position != Vector3::zero()) {
                                                        orig_TryUseSkill(instance, 6820, iTargetPos, true, _Position, false, true);
                                                        sleep(0.5);
                                                        orig_TryUseSkill(instance, 6820, iTargetPos, true, _Position, false, true);
                                                        sleep(0.5);
                                                        orig_TryUseSkill(instance, 6820, iTargetPos, true, _Position, false, true);
                                                        sleep(0.5);
                                                        orig_TryUseSkill(instance, 6820, iTargetPos, true, _Position, false, true);
                                                        sleep(0.5);
                                                        orig_TryUseSkill(instance, 6820, iTargetPos, true, _Position, false, true);
                                                        sleep(0.5);
                                                        orig_TryUseSkill(instance, 6820, iTargetPos, true, _Position, false, true);
                                                        break;
                                                    }
                                                }
                                            }
                                        }
                                    }
									
							if (Aim.Helper.Skills.Martis) {
							    if (Distance < 5.0f && CurHP < MaxEnemyHP) {
							        if (CurHP <= Auto) {
							            if (Vector3::Normalized(_Position - selfPos) != Vector3::zero()) {
                                            orig_TryUseSkill(instance, 5830, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), false, false);
                                            }}}}
							if (Aim.Helper.Skills.Balmond) {
						    	if (Distance < 5.0f && CurHP < MaxEnemyHP) {
							        if (CurHP <= Auto) {
							            if (Vector3::Normalized(_Position - selfPos) != Vector3::zero()) {
                                            orig_TryUseSkill(instance, 230, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), false, false);
										}
                                    }
								}
							}
                                    //Auto Combo 2
                                    if (Aim.Helper.AutoCombo.Tigreal) {
                                        if (EnemyDistance < TargetDistance && skillId == 20100) {
                                            
                                            orig_TryUseSkill(instance, 630, iTargetPos, true, selfPos, false, true);
                                        }
                                    }
                                    if (Aim.Helper.AutoCombo.Atlas) {
                                        if (EnemyDistance < TargetDistance && skillId == 20100) {
                                            
                                            orig_TryUseSkill(instance, 9330, iTargetPos, true, selfPos, false, true);
                                        }
                                    }
                                    if (Aim.Helper.AutoCombo.Franco1) {
                                        if (EnemyDistance < TargetDistance && skillId == 20100) {
                                            
                                            orig_TryUseSkill(instance, 1030, iTargetPos, true, selfPos, false, true);
                                        }
                                    }
                                    if (Aim.Helper.AutoCombo.Lolita) {
                                        if (EnemyDistance < TargetDistance && skillId == 20100) {
                                            
                                            orig_TryUseSkill(instance, 2030, iTargetPos, true, _Position, false, true);
                                        }
                                    }
                                    //Auto Combo 3
                                    if (Aim.Helper.AutoCombo.Selena) {
                                        if (EnemyDistance < TargetDistance && skillId == 6310) {
                                            
                                            orig_TryUseSkill(instance, 6320, iTargetPos, true, _Position, false, true);
                                        }
                                    }
                                    if (Aim.Helper.AutoCombo.Badang) {
                                        if (EnemyDistance < TargetDistance && skillId == 7720) {
                                            
                                            orig_TryUseSkill(instance, 7730, iTargetPos, true, _Position, false, true);
                                        }
                                    }
                                    if (Aim.Helper.AutoCombo.Saber1) {
                                        if (EnemyDistance < TargetDistance && skillId == 320) {
                                            
                                            orig_TryUseSkill(instance, 330, iTargetPos, true, selfPos, false, true);
                                        }
                                    }
                                    if (Aim.Helper.AutoCombo.Harith) {
                                        if (EnemyDistance < TargetDistance && skillId == 100 * HeroID + 00) {
                                            
                                            orig_TryUseSkill(instance, 7320, iTargetPos, true, _Position, false, true);
                                        }
                                    }
                                    //Auto Combo 4
                                    if (Aim.Helper.AutoCombo.Brody) {
                                        if (EnemyDistance < TargetDistance && skillId == 10010) {
                                            
                                            orig_TryUseSkill(instance, 10030, iTargetPos, true, _Position, false, true);
                                        }
                                    }
                                    if (Aim.Helper.AutoCombo.Franco2) {
                                        if (EnemyDistance < TargetDistance && skillId == 1010) {
                                            
                                            orig_TryUseSkill(instance, 1030, iTargetPos, true, selfPos, false, true);
                                        }
                                    }
                                    if (Aim.Helper.AutoCombo.Xavier) {
                                        if (EnemyDistance < TargetDistance && skillId == 11510) {
                                            orig_TryUseSkill(instance, 11520, iTargetPos, true, _Position, false, true);
                                            
                                        }
                                    }
									if (Aim.Helper.AutoCombo.Xavier2) {
                                        if (EnemyDistance < TargetDistance && skillId == 11520) {
                                            orig_TryUseSkill(instance, 11510, iTargetPos, true, _Position, false, true);
                                            
                                        }
                                    }
									if (Aim.Helper.AutoCombo.Xavier3) {
                                        if (EnemyDistance < TargetDistance && skillId == 11520) {
                                            orig_TryUseSkill(instance, 11530, iTargetPos, true, _Position, false, true);
                                            
                                        }
                                    }
									if (Aim.Helper.AutoCombo.Xavier4) {
                                        if (EnemyDistance < TargetDistance && skillId == 11510) {
                                            orig_TryUseSkill(instance, 11530, iTargetPos, true, _Position, false, true);
                                            
                                        }
                                    }
                                    if (Aim.Helper.AutoCombo.Saber2) {
                                        if (EnemyDistance < TargetDistance && skillId == 310) {
                                            
                                            orig_TryUseSkill(instance, 330, iTargetPos, true, selfPos, false, true);
                                        }
                                    }
                                    //More Feature
                                    if (Aim.Helper.MoreFeature.Chou) {
                                        if (EnemyDistance < TargetDistance && skillId == 2630) {
                                            
                                            orig_TryUseSkill(instance, 20100, iTargetPos, true, _Position, false, true);
                                        }
                                    }
									if (Aim.Helper.MoreFeature.Chou2) {
                                        if (EnemyDistance < TargetDistance && skillId == 20100) {
                                            
                                            orig_TryUseSkill(instance, 2630, iTargetPos, true, _Position, false, true);
                                        }
                                    }
                                    if (Aim.Helper.MoreFeature.Pharsa) {
                                        if (EnemyDistance < TargetDistance && skillId == 5230) {
                                            if (_Position != Vector3::zero()) {
                                                orig_TryUseSkill(instance, 5230, iTargetPos, true, _Position, false, true);
                                                sleep(0.5);
                                                orig_TryUseSkill(instance, 5230, iTargetPos, true, _Position, false, true);
                                                sleep(0.5);
                                                
                                                
                                                     
                                                    }
                                                }
                                            }
											
									if (Aim.Helper.MoreFeature.Yve) {
                                        if (EnemyDistance < TargetDistance && skillId == 5230) {
                                            if (_Position != Vector3::zero()) {
                                                orig_TryUseSkill(instance, 5230, iTargetPos, true, _Position, false, true);
                                                sleep(0.5);
                                                orig_TryUseSkill(instance, 5230, iTargetPos, true, _Position, false, true);
                                                sleep(0.5);
                                                orig_TryUseSkill(instance, 5230, iTargetPos, true, _Position, false, true);
                                                if (EnemyDistance < TargetDistance && skillId == 5230) {
                                                    if (_Position != Vector3::zero()) {
                                                        orig_TryUseSkill(instance, 5230, iTargetPos, true, _Position, false, true);
                                                        sleep(0.5);
                                                        orig_TryUseSkill(instance, 5230, iTargetPos, true, _Position, false, true);
                                                        sleep(0.5);
                                                        orig_TryUseSkill(instance, 5230, iTargetPos, true, _Position, false, true);
                                                        break;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (Aim.Helper.MoreFeature.Kimmy) {
                                        if (_Position != Vector3::zero() && Distance < 6.5f) {  
                                            orig_TryUseSkill(instance, 7113, Vector3::Normalized(_Position - selfPos), true, selfPos, false, true);
                                        } else if (_Position != Vector3::zero() && Distance < 6.5f) {
                                            orig_TryUseSkill(instance, 7110, Vector3::Normalized(_Position - selfPos), true, selfPos, false, true);
                                        }
                                    }
                                    //Auto Ultimate V1
                                    if (Aim.Helper.AutoUltimate.Beatrix) {
                                        if (Distance < 20.0f && CurHP < MaxEnemyHP) {
                         if (CurHP <= 1000.0f) {
                         if (Vector3::Normalized(_Position - selfPos) != Vector3::zero()) {
                                                orig_TryUseSkill(instance, 2010530, iTargetPos, true, _Position, false, true);
                                            }}}}
                                        
                                    
                                    if (Aim.Helper.AutoUltimate.Xavier) {
                                        if (Distance < 20.0f && CurHP < MaxEnemyHP) {
                         if (CurHP <= 1000.0f) {
                         if (Vector3::Normalized(_Position - selfPos) != Vector3::zero()) {
                                                orig_TryUseSkill(instance, 11530, iTargetPos, true, _Position, false, true);
                                            }}}}
                                        
                                    
                                    if (Aim.Helper.AutoUltimate.Granger) {
                                        if (EnemyDistance < TargetDistance && CurHP <= TargetHP) {
                                            if (_Position != Vector3::zero()) {
                                                orig_TryUseSkill(instance, 7930, iTargetPos, true, _Position, false, true);
                                                sleep(0.5);
                                                orig_TryUseSkill(instance, 7930, iTargetPos, true, _Position, false, true);
                                                sleep(0.5);
                                                orig_TryUseSkill(instance, 7930, iTargetPos, true, _Position, false, true);
                                                sleep(0.5);
                                                orig_TryUseSkill(instance, 7930, iTargetPos, true, _Position, false, true);
                                                break;
                                            }
                                        }
                                    }
                                        
                                    
                                    if (Aim.Helper.AutoUltimate.Balmond) {
                                        if (Distance < 20.0f && CurHP < MaxEnemyHP) {
                         if (CurHP <= 1000.0f) {
                         if (Vector3::Normalized(_Position - selfPos) != Vector3::zero()) {
                                                orig_TryUseSkill(instance, 230, iTargetPos, true, _Position, false, true);
                                            }}}}
                                    //Auto Ultimate V2
                                    if (Aim.Helper.AutoUltimate.Layla) {
                         if (Distance < 20.0f && CurHP < MaxEnemyHP) {
                         if (CurHP <= 1000.0f) {
                         if (Vector3::Normalized(_Position - selfPos) != Vector3::zero()) {
                              orig_TryUseSkill(instance, 1830, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), false, true);
                            }}}}
                                    if (Aim.Helper.AutoUltimate.Moskov) {
                                        if (Distance < 20.0f && CurHP < MaxEnemyHP) {
                         if (CurHP <= 1000.0f) {
                         if (Vector3::Normalized(_Position - selfPos) != Vector3::zero()) {
                                                orig_TryUseSkill(instance, 3130, iTargetPos, true, _Position, false, true);
                                        }}}}
                                    if (Aim.Helper.AutoUltimate.Nana) {
                                        if (Distance < 20.0f && CurHP < MaxEnemyHP) {
                         if (CurHP <= 1000.0f) {
                         if (Vector3::Normalized(_Position - selfPos) != Vector3::zero()) {
                                                orig_TryUseSkill(instance, 530, iTargetPos, true, _Position, false, true);
                                         }}}}
                                    if (Aim.Helper.AutoUltimate.Gord) {
                                        if (EnemyDistance < TargetDistance && CurHP <= TargetHP) {
                                            if (Vector3::Normalized(_Position - selfPos) != Vector3::zero()) {
                                                orig_TryUseSkill(instance, 2330, iTargetPos, true, _Position, false, true);
                                            }
                                        }
                                    }
                                    //Auto Ultimate V3
                                    if (Aim.Helper.AutoUltimate.Hilda) {
                                        if (Distance < 20.0f && CurHP < MaxEnemyHP) {
                         if (CurHP <= 1000.0f) {
                         if (Vector3::Normalized(_Position - selfPos) != Vector3::zero()) {
                                                orig_TryUseSkill(instance, 3530, iTargetPos, true, _Position, false, true);
                                        }}}}
                                    if (Aim.Helper.AutoUltimate.Martis) {
                                        if (Distance < 20.0f && CurHP < MaxEnemyHP) {
                         if (CurHP <= 1000.0f) {
                         if (Vector3::Normalized(_Position - selfPos) != Vector3::zero()) {
                                                orig_TryUseSkill(instance, 5830, iTargetPos, true, selfPos, false, true);
                                            }}}}
                                    if (Aim.Helper.AutoUltimate.Thamuz) {
                                        if (EnemyDistance < TargetDistance && MyHealth <= 2500) {
                                            if (Vector3::Normalized(_Position - selfPos) != Vector3::zero()) {
                                                orig_TryUseSkill(instance, 7230, iTargetPos, true, selfPos, false, true);
                                            }
                                        }
                                    }
                                    if (Aim.Helper.AutoUltimate.Argus) {
										if (Distance < 10.0f && MyHealth < MaxEnemyHP) {
                         if (MyHealth <= 2500) {
                                        //if (EnemyDistance < TargetDistance && MyHealth <= 2500) {
                                            if (Vector3::Normalized(_Position - selfPos) != Vector3::zero()) {
                                                orig_TryUseSkill(instance, 4530, iTargetPos, true, selfPos, false, true);
                                            }}}}
                                        
                                    
                                    //Auto Defense
                                    if (Aim.Helper.AutoDefense.Executed) {
                                        if (EnemyDistance < TargetDistance && CurHP <= TargetHP) {
                                            if (Vector3::Normalized(_Position - selfPos) != Vector3::zero()) {
                                                orig_TryUseSkill(instance, 20150, iTargetPos, true, selfPos, false, true);
                                            }
                                        }
                                    }
                                    if (Aim.Helper.AutoDefense.FlameShoot) {
                                        if (EnemyDistance < TargetDistance && CurHP <= TargetHP) {
                                            if (Vector3::Normalized(_Position - selfPos) != Vector3::zero()) {
                                                orig_TryUseSkill(instance, 20140, iTargetPos, true, selfPos, false, true);
                                            }
                                        }
                                    }
                                    if (Aim.Helper.AutoDefense.Vengeance) {
                                    if (Distance < 20.0f &&  MyHealth < MaxEnemyHP) {
                         if (MyHealth <= 2500) {
                      /*   if (Vector3::Normalized(_Position - selfPos) != Vector3::zero()) {
                                        if (EnemyDistance < TargetDistance && MyHealth <= 2500) {*/
                                            if (Vector3::Normalized(_Position - selfPos) != Vector3::zero()) {
                                                orig_TryUseSkill(instance, 20150, iTargetPos, true, selfPos, false, true);
                                            }}}}
                                        
                                    
                                    if (Aim.Helper.AutoDefense.Flicker) {
                                        if (EnemyDistance < TargetDistance && MyHealth <= 2500) {
                                            if (Vector3::Normalized(_Position - selfPos) != Vector3::zero()) {
                                                orig_TryUseSkill(instance, 20140, iTargetPos, true, selfPos, false, true);
                                            }
                                        }
                                    }
                                    if (Aim.Helper.AutoDefense.Aegis) {
                                        if (EnemyDistance < TargetDistance && MyHealth <= 2500) {
                                            if (Vector3::Normalized(_Position - selfPos) != Vector3::zero()) {
                                                orig_TryUseSkill(instance, 20140, iTargetPos, true, selfPos, false, true);
                                                }
                                            }
                                        }
                                    }//EntityPos
                                }//Aim
                            }//Aim
                        }//Aim
                        //Basic
                        if (EntityPos != Vector3::zero()) {
                        auto targetLockPos = Vector3::Normalized(EntityPos - selfPos);
                        if (Aim.Helper.Skills.Basic) {
                            if (skillId == 100 * HeroID + 00) {
                                isDoneAim = true;
                                orig_TryUseSkill(instance, skillId, targetLockPos, dirDefault, pos, bCommonAtk, bAuto, bAlong, bCache, isInFirstDragRange);
                            }
                        }
                        //Spell
                        if (Aim.Helper.Skills.Spell) {
                            if (skillId == 20100 || skillId == 20140) {
                                isDoneAim = true;
                                orig_TryUseSkill(instance, skillId, targetLockPos, dirDefault, pos, bCommonAtk, bAuto, bAlong, bCache, isInFirstDragRange);
                            }
                        }
                        //Skill 1
                        if (Aim.Helper.Skills.Skill1) {
                            if (skillId == 100 * HeroID + 10) {
                                isDoneAim = true;
                                orig_TryUseSkill(instance, skillId, targetLockPos, dirDefault, pos, bCommonAtk, bAuto, bAlong, bCache, isInFirstDragRange);
                            }
                        }
                        //Skill 2
                        if (Aim.Helper.Skills.Skill2) {
                            if (skillId == 100 * HeroID + 20 || skillId == 2010520 /*Beatrix Skill2*/) {
                                isDoneAim = true;
                                orig_TryUseSkill(instance, skillId, targetLockPos, dirDefault, pos, bCommonAtk, bAuto, bAlong, bCache, isInFirstDragRange);
                            }
                        }
                        //Skill 3
                        if (Aim.Helper.Skills.Skill3) {
                            if (skillId == 100 * HeroID + 30 || skillId == 2010530 /*Beatrix Ulti*/) {
                                isDoneAim = true;
                                orig_TryUseSkill(instance, skillId, targetLockPos, dirDefault, pos, bCommonAtk, bAuto, bAlong, bCache, isInFirstDragRange);
                            }
                        }
                        //Skill 4
                        if (Aim.Helper.Skills.Skill4) {
                            if (skillId == 100 * HeroID + 40) {
                                isDoneAim = true;
                                orig_TryUseSkill(instance, skillId, targetLockPos, dirDefault, pos, bCommonAtk, bAuto, bAlong, bCache, isInFirstDragRange);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (!isDoneAim) {
        orig_TryUseSkill(instance, skillId, dir, dirDefault, pos, bCommonAtk, bAuto, bAlong, bCache, isInFirstDragRange);
    }
}

int CalculateRetriDamage(int m_Level, int m_KillWildTimes) {
    if (m_KillWildTimes < 5) {
        return 520 + (80 * m_Level);
    } else {
        return 1.5 * (520 + (80 * m_Level));
    }
}

void (*orig_UpdateRetribution)(void *instance);
void UpdateRetribution(void *instance) {
    if (Aim.Helper.AutoRetribution.Buff1 || Aim.Helper.AutoRetribution.Buff2 || Aim.Helper.AutoRetribution.Rockursa || Aim.Helper.AutoRetribution.Scaled || Aim.Helper.AutoRetribution.Lord || Aim.Helper.AutoRetribution.Turtle || Aim.Helper.AutoRetribution.Crab || Aim.Helper.AutoRetribution.Litho) {
        if (instance != NULL) {
            void *BattleManager_Instance;
            Il2CppGetStaticFieldValue("Assembly-CSharp.dll", "", "BattleManager", "Instance", &BattleManager_Instance);
            if (BattleManager_Instance) {
                auto m_LocalPlayerShow = *(uintptr_t *) ((uintptr_t)BattleManager_Instance + BattleManager_m_LocalPlayerShow);
                if (m_LocalPlayerShow) {
                    auto selfPos = *(Vector3 *) ((uintptr_t)m_LocalPlayerShow + ShowEntity__Position);
                    if (selfPos != Vector3::zero()) {
                        auto m_Level = *(int *) ((uintptr_t)m_LocalPlayerShow + EntityBase_m_Level);
                        auto _logicFighter = *(uintptr_t *) ((uintptr_t)m_LocalPlayerShow + ShowEntity__logicFighter);
                        int iCalculateDamage;
                        if (_logicFighter) {
                            auto m_KillWildTimes = *(int *) ((uintptr_t)_logicFighter + LogicPlayer_m_KillWildTimes);
                            iCalculateDamage = CalculateRetriDamage(m_Level, m_KillWildTimes);
                        }
                        monoList<void **> *m_ShowMonsters = *(monoList<void **> **) ((uintptr_t)BattleManager_Instance + BattleManager_m_ShowMonsters);
                        if (m_ShowMonsters) {
                            for (int i = 0; i < m_ShowMonsters->getSize(); i++) {
                                auto Pawn = m_ShowMonsters->getItems()[i];
                                if (!Pawn) continue;
                                auto m_ID = *(int *) ((uintptr_t)Pawn + EntityBase_m_ID);
                                if (MonsterToString(m_ID) == "") continue;
                                auto m_bSameCampType = *(bool *) ((uintptr_t)Pawn + EntityBase_m_bSameCampType);
                                if (m_bSameCampType) continue;
                                auto m_bDeath = *(bool *) ((uintptr_t)Pawn + EntityBase_m_bDeath);
                                if (m_bDeath) continue;
                                auto m_IsDeathProgress = *(bool *) ((uintptr_t)Pawn + EntityBase_m_IsDeathProgress);
                                if (m_IsDeathProgress) continue;
                                auto _Position = *(Vector3 *) ((uintptr_t)Pawn + ShowEntity__Position);
                                float Distance = (int) Vector3::Distance(selfPos, _Position);
                                float CurHP = *(int *) ((uintptr_t)Pawn + EntityBase_m_Hp);
                                float MaxHP = *(int *) ((uintptr_t)Pawn + EntityBase_m_HpMax);
                                if (!m_bDeath && !m_IsDeathProgress) {
                                    if (Distance < 8.0f && CurHP < MaxHP) {
                                        if (CurHP <= iCalculateDamage) {
                                            if (m_ID == 2004 && Aim.Helper.AutoRetribution.Buff1 || m_ID == 2005 && Aim.Helper.AutoRetribution.Buff2 || m_ID == 2002 && Aim.Helper.AutoRetribution.Lord || m_ID == 2003 && Aim.Helper.AutoRetribution.Turtle || m_ID == 2013 && Aim.Helper.AutoRetribution.Crab || m_ID == 2011 && Aim.Helper.AutoRetribution.Crab || m_ID == 2072 && Aim.Helper.AutoRetribution.Litho || m_ID == 2056 && Aim.Helper.AutoRetribution.Litho || Aim.Helper.AutoRetribution.Rockursa /*Rockursa*/ || m_ID == 2006 && Aim.Helper.AutoRetribution.Scaled /*Scaled*/ ) {
                                                if (Vector3::Normalized(_Position - selfPos) != Vector3::zero()) {
                                                    orig_TryUseSkill(instance, 20020, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), false, true);
                                                 }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    orig_UpdateRetribution(instance);
}

