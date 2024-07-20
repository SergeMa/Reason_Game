// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy_Base.h"
#include "AI_PatrolRoute.h"

AAI_PatrolRoute* AEnemy_Base::GetPatrolRoute()
{
	if (PatrolRoute) return PatrolRoute;

	return nullptr;
}