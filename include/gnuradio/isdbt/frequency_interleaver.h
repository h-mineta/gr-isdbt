/* -*- c++ -*- */
/*  
 * Copyright 2015, 2016, 2017, 2018, 2019, 2020, 2021
 *   Federico "Larroca" La Rocca <flarroca@fing.edu.uy>
 *   Pablo Belzarena 
 *   Gabriel Gomez Sena 
 *   Pablo Flores Guridi 
 *   Victor Gonzalez Barbone
 *
 *   Instituto de Ingenieria Electrica, Facultad de Ingenieria,
 *   Universidad de la Republica, Uruguay.
 *  
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *  
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *  
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 *
 */

#ifndef INCLUDED_ISDBT_FREQUENCY_INTERLEAVER_H
#define INCLUDED_ISDBT_FREQUENCY_INTERLEAVER_H

#include <gnuradio/isdbt/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace isdbt {

    /*!
     * \brief Performs frequency interleaving: intra-segment (randomization and rotation) and
     * inter-segment interleaving. 
     *
     * TODO: this block does not currently support differential 
     * modulation, which requires a separate treatment. It will
     * assume all segments are coherently modulated. 
     * \ingroup isdbt
     *
     */
    class ISDBT_API frequency_interleaver : virtual public gr::sync_block
    {
     public:
      typedef std::shared_ptr<frequency_interleaver> sptr;

      /*!
       * \brief Performs frequency interleaver: intra-segment 
       * (randomization and rotation) and inter-segment interleaving. 
       *
       * \param oneseg It indicates whether a 1-seg transmission is present in the transmission. 
       * \param mode It indicates the transmission mode (either 1, 2 or 3). 
       */
      static sptr make(bool oneseg, int mode);
    };

  } // namespace isdbt
} // namespace gr

#endif /* INCLUDED_ISDBT_FREQUENCY_INTERLEAVER_H */

