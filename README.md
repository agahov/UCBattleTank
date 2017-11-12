# UCBattleTank
"Udemy" course. Hand-to-hand tank battle, open world, simple AI and advance control system on UE4

## RoadMam
* init
* setup git rep
* create blank project
* add simple landscape 
 - two color 
 - 1000x1000 meters
* recreate low poly landscape
* add texture to landscape material
* add tank meshes,  create sockets, create TankBP with mesh 
* config Tank_BP, create BP_UCTankBattleGameMode
* camera input setup
* add Azimuth Gimblal - fix camera rotation
* add Aim UI
* start mainMenu 
* add Parent C++ classes for BP_TankPlayerController and TankPawn
* move BeginPlayer form BP_TankPayerController to C++ TankPlayerController
* add GetPlayerTank method to TankAIController
* add Tick method to TankPlayerController, start AimTowardsCrossHair
* add GetSightRayHitLocation template method
* calculate crosshairScreenLocation
* add GetLookDirection method
* complete GetSightRayHitLocation 
* add Tank.AimAt() method, used for all controllers
* add TankAimingComponent
* set Barrel through Blueprint
* add LaunchSpeed
* invoke SuggestProjectileVelocity
* add MoveBarrelTowards
* create and setup TankBarrel Component
* refacloring
* make forwardeclaration
* Rotate Barrel
* if miss barrel stop not moving to zero  
* Rotate Turret(self)
* Setup default values
* Fire method, Projectile class
* remove collision bound form turret and barrel
* SpawnActor for projectile
* recommit prev
* add ProjectileMovementComponent in c++






 