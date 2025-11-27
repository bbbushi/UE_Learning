// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickableActor_Base.generated.h"

UCLASS()
class PROJECT_LEARN_API APickableActor_Base : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickableActor_Base();
	//开始重叠
	UFUNCTION()void BeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	 UPrimitiveComponent* OtherComp,int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	// Called when the game starts or when spawned
	//创建事件发生和拾取函数
	virtual void BeginPlay() override;
	virtual void PlayerPickedUp(class AProject_LearnCharacter* Player);
	
	UPROPERTY(VisibleDefaultsOnly, Category = "PickableItem")
	class USphereComponent*CollisionComp;
	//视觉上用于表示可收集物
	UPROPERTY(VisibleDefaultsOnly, Category = "PickableItem")
	class UStaticMeshComponent* MeshComp;
	//为可收集物提供圆周运动
	UPROPERTY(VisibleDefaultsOnly, Category = "PickableItem")
	class URotatingMovementComponent* RotationComp;
	//拾取物品音效
	UPROPERTY(EditAnywhere, Category = PickableItem)
	class USoundBase* PickupSound;
	 

public:	
	// Called every frame
	

};
