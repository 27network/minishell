/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   features.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 08:58:04 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/04 17:01:27 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FEATURES_H
# define FEATURES_H

// Defaults

/// Minishell bonuses
# define FEAT_PARSER_WILDCARD 0
# define FEAT_TKN_OR 0
# define FEAT_TKN_AND 0
# define FEAT_TKN_PAR 0

/// Minishell extras
# define FEAT_PROMPT_PICKER 0

/// 42sh features
# define FEAT_TKN_
# define FEAT_TKN_ESCAPE 0
# define FEAT_PARSER_WILDCARD_EXT 0

// Definitions
# ifdef BONUS_MSH
#  define FEAT_PARSER_WILDCARD 1
#  define FEAT_TKN_OR 1
#  define FEAT_TKN_AND 1
#  define FEAT_TKN_PAR 1
# endif

# ifdef EXTRA_MSH
#  define FEAT_PROMPT_PICKER 1
# endif

# ifdef BONUS_42SH // heheheha
#  define FEAT_PARSER_WILDCARD_EXT 1
#  define FEAT_TKN_ESCAPE 1
# endif

#endif // FEATURES_H
