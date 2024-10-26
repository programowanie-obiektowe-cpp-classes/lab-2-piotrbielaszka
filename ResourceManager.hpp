#pragma once

#include "Resource.hpp"

using namespace std;

class ResourceManager
{
private:
    unique_ptr< Resource > res;

public:
    ResourceManager() : res(make_unique< Resource >()) {}
    ResourceManager(const ResourceManager& res2) : res(make_unique< Resource >(*res2.res)) {}
    ResourceManager(ResourceManager&& res2) : res(move(res2.res)) {}
    ~ResourceManager() {}
    ResourceManager& operator=(const ResourceManager& res2)
    {
        if (this != &res2) {
            res = make_unique< Resource >(*res2.res);
        }
        return *this;
    }
    ResourceManager& operator=(ResourceManager&& res2)
    {
        if (this != &res2) {
            res = move(res2.res);
        }
        return *this;
    }
    double get() { return res->get(); }
};
