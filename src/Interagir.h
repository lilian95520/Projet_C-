#pragma once

// Interface pour toutes les entités du jeu avec lesquelles on peut interagir
struct Interagir {
    virtual void interagir() = 0;
    virtual ~Interagir() = default;
};