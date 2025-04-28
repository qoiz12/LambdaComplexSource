//========= Copyright Lambda Complex, All rights reserved. ============//
//
// Purpose: 
//
//=============================================================================//

#ifndef NPC_FEMALE_BO_H
#define NPC_FEMALE_BO_H
#pragma once

#include "npc_blackops.h"

//=========================================================
class CNPC_FemaleBo : public CNPC_CBlackOps
{
	DECLARE_CLASS( CNPC_FemaleBo, CNPC_CBlackOps );
//	DECLARE_DATADESC();

public: 
	void		Spawn( void );
	void		Precache( void );
	void		DeathSound( const CTakeDamageInfo &info );
	void		PrescheduleThink( void );
	void		BuildScheduleTestBits( void );
	int			SelectSchedule ( void );
	float		GetHitgroupDamageMultiplier( int iHitGroup, const CTakeDamageInfo &info );
	void		HandleAnimEvent( animevent_t *pEvent );
	void		OnChangeActivity( Activity eNewActivity );
	void		Event_Killed( const CTakeDamageInfo &info );
	void		OnListened();

	void		ClearAttackConditions( void );

	bool		m_fIsBlocking;

	bool		IsLightDamage( const CTakeDamageInfo &info );
	bool		IsHeavyDamage( const CTakeDamageInfo &info );

	virtual	bool		AllowedToIgnite( void ) { return true; }

private:
	bool		ShouldHitPlayer( const Vector &targetDir, float targetDist );
};

#endif // NPC_COMBINES_H
