#include <benchmark/benchmark.h>
#include <chrono>
#include "../Core/Graphic/Image.hpp"
#include "../Core/ECS/Entity.hpp"
#include "../App/SpaceInvader/World.hpp"
#include "../App/SpaceInvader/Systems/MovementSystem.hpp"
#include "../App/SpaceInvader/Systems/LifecycleSystem.hpp"
#include "../App/Utils/GameSettings.hpp"
#include "../App/Factory/EntityFactory.hpp"

GameSettings gBenchmarkSettings{
    Position{42, 70},
    HP{100}, HP{50}, HP{10}, 10ULL,
    std::chrono::milliseconds(200),
    FinishPoint{10},
    FinishPoint{-1}, 
    Width{2},
    Height{2},
    SpawnRange{10, 80}, 
    SpawnRange{-10, -100}
};

static void BM_CreateBullet(benchmark::State& state)
{
    const int bulletCount = state.range(0);

    for(auto _ : state)
    {
        World world(Entity(EntityType::PLAYER, Image(10, 10)));

        for(size_t i = 0ULL; i < bulletCount; i++)
        {
            ecs_system::initBullet(world, gBenchmarkSettings);
            ecs_system::moveBullets(world, gBenchmarkSettings);
            ecs_system::bulletFinish(world, gBenchmarkSettings);
        }

        benchmark::DoNotOptimize(world);
    }
}

BENCHMARK(BM_CreateBullet) -> Arg(1000);

BENCHMARK_MAIN();