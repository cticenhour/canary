[Mesh]
  [gmg]
    type = GeneratedMeshGenerator
    dim = 2
    nx = 20
    ny = 20
  []
[]

[Variables]
  [u]
  []
[]

[Kernels]
  [diff]
    type = LaplaceYoungDiffusion
    variable = u
  []
  [reaction]
    type = Reaction
    variable = u
  []
[]

[BCs]
  [neumann]
    type = NeumannBC
    variable = u
    boundary = 'left right top bottom'
    value = 0.2
  []
[]

[Executioner]
  type = Steady
  solve_type = 'PJFNK'
  petsc_options_iname = '-pc_type -pc_hypre_type'
  petsc_options_value = 'hypre boomeramg'
[]

[Outputs]
  exodus = true
[]
