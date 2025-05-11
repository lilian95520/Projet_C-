#pragma once

/// Interface pour toutes les entités du jeu avec lesquelles on peut interagir
struct Interagir {
    /// Affiche un message ou fait une action spécifique
    virtual void interagir() = 0;
    virtual ~Interagir() = default;
};