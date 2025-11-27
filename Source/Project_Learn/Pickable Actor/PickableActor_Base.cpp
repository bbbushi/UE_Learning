// Fill out your copyright notice in the Description page of Project Settings.


#include "PickableActor_Base.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "Project_Learn/Project_LearnCharacter/Project_LearnCharacter.h"
#include "Kismet/GameplayStatics.h" 

// Sets default values
APickableActor_Base::APickableActor_Base()
{
	//初始化USphereComponent的SphereComp变量
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	//初始化半径为30
	CollisionComp->InitSphereRadius(30.0f);
	//设置碰撞
	CollisionComp->BodyInstance.SetCollisionProfileName("OverlayAllDynamic");
	//分配根组件
	RootComponent = CollisionComp;
	//类比以上代码初始化UStaticMeshComponent 
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	//将meshcomp附加到根组件
	MeshComp->AttachToComponent(RootComponent,FAttachmentTransformRules::KeepWorldTransform);
	//初始化碰撞状态
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	//初始化Rotationcomp
	RotationComp = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("RotationComp"));
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}
//生成音效
void APickableActor_Base::PlayerPickedUp(AProject_LearnCharacter* Player)
{
	if (class UWorld* World = GetWorld())
	{
		if (PickupSound) 
		{
			UGameplayStatics::SpawnSoundAtLocation(World, PickupSound, GetActorLocation());
		}
	}
	Destroy();
}
void APickableActor_Base::BeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(class AProject_LearnCharacter* Player = Cast<AProject_LearnCharacter>(OtherActor))
	{
		PlayerPickedUp(Player);
	}
}

// Called when the game starts or when spawned
void APickableActor_Base::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame


