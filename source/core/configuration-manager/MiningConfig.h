#ifndef SF1V5_MINING_CONFIG_H_
#define SF1V5_MINING_CONFIG_H_

#include <ir/index_manager/index/IndexerCollectionMeta.h>

#include <stdint.h>
#include <string>
#include <map>


namespace sf1r
{
  
  /**
    * @brief   stores TG parameters
    */
  class TaxonomyPara
  {
      public:
          TaxonomyPara(){}
      private:
          friend class boost::serialization::access;

          template <typename Archive>
              void serialize( Archive & ar, const unsigned int version )
              {
                  ar & top_docnum;
                  ar & levels;
                  ar & per_levelnum;
                  ar & candidate_labelnum;
                  ar & enable_nec;
                  ar & max_peopnum;
                  ar & max_locnum;
                  ar & max_orgnum;
              }


      public:
          /**
            * @brief the number of top docs used to generate the taxonomy.
            */
          uint32_t top_docnum;

          /// @brief  the levels in the taxonomy.
          uint32_t levels;

          /**
            * @brief  the number of nodes in each level
            */
          uint32_t per_levelnum;

          /**
            * @brief  the maximum number of labels inputed to the taxonomy generation.
            */
          uint32_t candidate_labelnum;
          
          bool enable_nec;
          
          uint32_t max_peopnum;
          
          uint32_t max_locnum;
          
          uint32_t max_orgnum;

  };

  /**
    * @brief   the parameters for query recommend
    */
  class RecommendPara
  {

      private:
          friend class boost::serialization::access;

          template <typename Archive>
              void serialize( Archive & ar, const unsigned int version )
              {
                  ar & recommend_num & popular_num & realtime_num ;
              }
      public:
          /**
            * @brief  the number of recommend items to display
            */
          uint32_t recommend_num;
          
          uint32_t popular_num;
          
          uint32_t realtime_num;

  };

  
  /**
    * @brief   Stores "Store strategy" configuration of IndexManager
    */
  class SimilarityPara
  {

      private:
          friend class boost::serialization::access;

          template <typename Archive>
              void serialize( Archive & ar, const unsigned int version )
              {
                  ar & docnum_limit;
                  ar & termnum_limit;
              }
      public:
          /// @brief  the number of docs in idf accumulators.
          uint32_t docnum_limit;
          /// @brief the number of terms in tf accumulators.
          uint32_t termnum_limit;
  };
  
  /**
    * @brief   the parameters for document classification
    */
  class DocumentClassificationPara
  {

      private:
          friend class boost::serialization::access;

          template <typename Archive>
              void serialize( Archive & ar, const unsigned int version )
              {
                  ar & customize_training & encoding_type;
              }
      public:
          /**
            * @brief  the number of recommend items to display
            */
          bool customize_training;
          izenelib::util::UString::EncodingType encoding_type;
          

  };

  /**
    * @brief   the parameters for image search.
    */
  class IsePara
  {

      private:
          friend class boost::serialization::access;

          template <typename Archive>
              void serialize( Archive & ar, const unsigned int version )
              {
                  ar & build_img_index & store_locally & max_img_num& related_img_num;
              }
      public:
          /**
            * @brief  the number of recommend items to display
            */
          bool build_img_index ;
          bool store_locally;
          uint32_t max_img_num;
          uint32_t related_img_num;

  };

    /**
     * @brief   The configure unit for mining manager
     */
    class MiningConfig
    {

        public:

            

           
        public:
            //----------------------------  CONSTRUCTORS  ----------------------------

            MiningConfig() {}

            ~MiningConfig() {}



        private:

            friend class boost::serialization::access;

            template <typename Archive>
                void serialize( Archive & ar, const unsigned int version )
                {
                    ar & taxonomy_param;
                    ar & recommend_param;
                    ar & similarity_param;
                    ar & dc_param;
                    ar & ise_param;
                }

        public:

            TaxonomyPara taxonomy_param;

            RecommendPara recommend_param;
            SimilarityPara similarity_param;

            DocumentClassificationPara dc_param;

            IsePara ise_param;

    };

} // namespace

#endif //_MINING_CONFIG_H_