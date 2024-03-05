{
  description = "A development environment for minishell";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  };

  outputs = {
    self,
    nixpkgs,
  }: let
    system = "x86_64-linux";
    pkgs = nixpkgs.legacyPackages.${system};
  in {
    devShells.${system}.default =
      (pkgs.mkShell.override {
        stdenv = pkgs.stdenvAdapters.useMoldLinker pkgs.clang17Stdenv;
      }) {
        name = "minishell";
        packages = with pkgs; [
          readline
          valgrind
        ];
      };
  };
}
# vim: ts=2 sw=2 et
