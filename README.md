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
* EditDefaultsOnly
* Simplify collision 
* start throttle
* AddForceToLocation
* Physics and friction settings
* add UTankMovementComponent
* add Intend move forward
* init and use UTankMovementComponent
* IntendTurnRight IntendTurnLeft
* Add NavMeshVolume
* add RequestDirectMove method
* use DotProduct for AI forward moveing
* moving
* Use Blueprint Variables
* create enum FiringState
* Refactoring
* back tick component to AimComponent
* finished aim ui, change colors 
* Sideways Friction
* OnComponentHit Event
* 176 Avoiding Boolean Flags
* 177 Improving Tank Aiming
* 178 Tweaking Tank AI
* 182 Preparing for Particles
* 183 Introducing Particle Systems
* 184 Particle Bounding Boxes
* 185 Using FAttachmentTransformRules
* 186 Radial Forces  Caching
* 187 Using GetTimerManager
* fix Tank down through ground
* fix warning "no collision box" for tank parts
* 188 Using TakeDamage on Actors
* 189 BlueprintPure  Health Bars
* 190 The Observer Pattern




 